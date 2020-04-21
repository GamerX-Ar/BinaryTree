#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H

#include "node.h"

typedef struct tree_t tree_t;

struct tree_t {
    node_t *root; // ссылка на корень

    void *(*traversal)(node_t *node, void *(*callback)(node_t *, T), T); // тип обхода

    node_t *(*create_node)(T value); // создать новую вершину
    void (*add)(node_t *node, tree_t *this); // добавить вершину
    unsigned int (*height)(tree_t *this); // вычислить высоту дерева
    unsigned int (*size)(tree_t *this); // вычислить размер дерева
    node_t *(*search)(T key, tree_t *this); // поиск вершины
    void (*destroy)(tree_t *this); // разрушить дерево (освободить память)

    void *(*call)(tree_t *this, void *(*callback)(node_t *, T), T); // выполнить метод с установленным типом обхода
};

void init_tree(tree_t *tree);

#endif //BINARYTREE_TREE_H
