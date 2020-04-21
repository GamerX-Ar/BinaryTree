/********************************************************
 *  БЛОК РЕАЛИЗАЦИИ ШАБЛОНА ПРОЕКТИРОВАНИЯ "СТРАТЕГИЯ"  *
 ********************************************************/
#include <stdlib.h>
#include "strategy.h"


/**
 * Симметричный обход.
 *
 * @param node  Вершина дерева
 * @param callback  Функция обратного вызова
 * @param key Kлюч
 * @return  Результат работы функции обратного вызова
 */
static void * inorder(node_t *node, void *(*callback)(node_t *, T), T key) {
    if ( !node ) return NULL;

    node_t *result = NULL;

    if ( (result = inorder(node->left, callback, key)) ) {
        return result;
    }
    if ( (result = callback(node, key)) ) {
        return result;
    }
    if ( (result = inorder(node->right, callback, key)) ) {
        return result;
    }

    return result;
}
/**
 * Прямой обход.
 *
 * @param node  Вершина дерева
 * @param callback  Функция обратного вызова
 * @param key  Kлюч
 * @return  Результат работы функции обратного вызова
 */
static void * preorder(node_t *node, void *(*callback)(node_t *, T), T key) {
    if ( !node ) return NULL;

    node_t *result = NULL;

    if ( (result = callback(node, key)) ) {
        return result;
    }
    if ( (result = inorder(node->left, callback, key)) ) {
        return result;
    }
    if ( (result = inorder(node->right, callback, key)) ) {
        return result;
    }

    return result;
}
/**
 * Обход снизу.
 *
 * @param node  Вершина дерева
 * @param callback  Функция обратного вызова
 * @param key  Kлюч
 * @return  Результат работы функции обратного вызова
 */
static void * postorder(node_t *node, void *(*callback)(node_t *, T), T key) {
    if ( !node ) return NULL;

    node_t *result = NULL;

    if ( (result = inorder(node->left, callback, key)) ) {
        return result;
    }
    if ( (result = inorder(node->right, callback, key)) ) {
        return result;
    }
    if ( (result = callback(node, key)) ) {
        return result;
    }

    return result;
}

traversal_t TRAVERSAL = {
        .inorder = &inorder,
        .preorder = &preorder,
        .postorder = &postorder
};
