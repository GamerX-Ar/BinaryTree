#ifndef BINARYTREE_CALLBACK_H
#define BINARYTREE_CALLBACK_H

#include "../tree/node.h"


typedef struct callback_t callback_t;

struct callback_t {
    void *(*print)(node_t *node, T key);
    void *(*search)(node_t *node, T key);
};

extern callback_t CALLBACKS;

#endif //BINARYTREE_CALLBACK_H
