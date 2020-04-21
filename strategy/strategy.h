#ifndef BINARYTREE_STRATEGY_H
#define BINARYTREE_STRATEGY_H

#include "../tree/node.h"


typedef struct traversal_t traversal_t;

// Все стратегии обхода
struct traversal_t {
    void *(*inorder)(node_t *, void *(*callback)(node_t *, T), T);
    void *(*preorder)(node_t *, void *(*callback)(node_t *, T), T);
    void *(*postorder)(node_t *, void *(*callback)(node_t *, T), T);
};

extern traversal_t TRAVERSAL;

#endif //BINARYTREE_STRATEGY_H
