#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "../strategy/strategy.h"
#include "../user_errors.h"


/**
 * Создать новую вершину.
 *
 * @param value  Данные вершины
 * @return Указатель на вершину
 */
node_t * create_node(T value) {
    // Выделить память под новый узел
    node_t *node = malloc(sizeof(node_t));
    if ( !node ) {
        printf("Out of memory!\n");
        exit(OUT_OF_MEMORY);
    }
    // Инициализировать новый узел
    node->value = value;
    node->left = node->right = NULL;

    return node;
}

void add_node_loop(node_t *new_node, node_t **node) {
    while ( (*node) ) { // пока узел существует
        if (new_node->value < (*node)->value) {  // значение новой вершины меньше - добавляем слева
            *node = (*node)->left;
        } else {  // значение новой вершины больше либо равно - добавляем справа
            *node = (*node)->right;
        }
    }
    *node = new_node;
}

/**
 * Добавить вершину к листу (лист станет поддеревом).
 *
 * @param new_node  Указатель на вершину, которую требуется добавить
 * @param node  Адрес указателя (не структуры! - т.е. фактически адрес на адрес)
 * @return
 */
node_t * add_node(node_t *new_node, node_t **node) {
    if ( !(*node) ) {  // если узел пуст
        *node = new_node;
    } else if (new_node->value < (*node)->value) {  // значение новой вершины меньше - добавляем слева
        (*node)->left = add_node(new_node, &(*node)->left);
    } else {  // значение новой вершины больше либо равно - добавляем справа
        (*node)->right = add_node(new_node, &(*node)->right);
    }
    return *node;
}

/**
 * Добавить вершину к дереву.
 *
 * @param node  Указатель на вершину, которую требуется добавить
 * @param this  Дерево
 */
void add(node_t *node, tree_t *this) {
//    add_node(node, &(this->root));
    add_node_loop(node, &(this->root));
}

/**
 * Вычислить высоту поддерева.
 *
 * @param node  Поддерево (вершина)
 * @return Высота
 */
unsigned int height_subtree(node_t *node) {
    if ( node == NULL ) return 0;

    unsigned int leftHeight = height_subtree(node->left);
    unsigned int rightHeight = height_subtree(node->right);

    return (leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1);
}

/**
 * Вычислить высоту дерева.
 *
 * @param tree  Дерево
 * @return Высота
 */
unsigned int height_tree(tree_t *tree) {
    return height_subtree(tree->root);
}

/**
 * Вычислить размер поддерева (кол-во вершин).
 *
 * @param node  Поддерево (вершина)
 * @return Размер
 */
unsigned int size_subtree(node_t *node) {
    return ( node == NULL ? 0 : size_subtree(node->left) + 1 + size_subtree(node->right) );
}

/**
 * Вычислить размер дерева (кол-во вершин).
 *
 * @param tree  Дерево
 * @return Размер
 */
unsigned int size_tree(tree_t *tree) {
    return size_subtree(tree->root);
}

/**
 * Поиск в поддереве.
 *
 * @param node Вершина
 * @param key  Ключ
 * @return Вершина, значение которой равно ключу.
 */
node_t * search_subtree(node_t *node, T key) {
    if ( !node ) return NULL;
    if ( key == node->value ) {
        return node;
    } else if(key < node->value) {
        return search_subtree(node->left, key);
    } else {
        return search_subtree(node->right, key);
    }
}

/**
 * Поиск по всему дереву.
 *
 * @param node Вершина
 * @param key  Ключ
 * @return Вершина, значение которой равно ключу.
 */
node_t * search_tree(T key, tree_t *tree) {
    return search_subtree(tree->root, key);
}

/**
 * Разрушить поддерево (освободить память).
 *
 * @param node  Поддерево (вершина)
 */
void destroy_node(node_t *node) {
    if ( node ) {
        destroy_node(node->left);
        destroy_node(node->right);
        free(node);
    }
}

/**
 * Разрушить дерево (освободить память).
 *
 * @param tree  Дерево
 */
void destroy_tree(tree_t *tree) {
    destroy_node(tree->root);
}

void * call(tree_t *this, void *(*callback)(node_t *, T), T key) {
    return this->traversal(this->root, callback, key);
}

void init_tree(tree_t *tree) {
    tree->root = NULL;
    tree->traversal = TRAVERSAL.preorder;
    tree->create_node = &create_node;
    tree->add = &add;
    tree->search = &search_tree;
    tree->height = &height_tree;
    tree->size = &size_tree;
    tree->destroy = &destroy_tree;
    tree->call = &call;
}
