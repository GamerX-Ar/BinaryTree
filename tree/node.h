#ifndef BINARYTREE_NODE_H
#define BINARYTREE_NODE_H

#include "../user_type.h"

typedef struct node_t node_t;

struct node_t {
    T value;
    node_t *left;
    node_t *right;
};

#endif //BINARYTREE_NODE_H
