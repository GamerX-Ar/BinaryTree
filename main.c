#include <stdio.h>
#include "tree/tree.h"
#include "callback/callback.h"
#include "strategy/strategy.h"


int main() {
    tree_t tree;

    init_tree(&tree);

    tree.traversal = TRAVERSAL.preorder;

    tree.add(tree.create_node('r'), &tree);
    tree.add(tree.create_node('o'), &tree);
    tree.add(tree.create_node('o'), &tree);
    tree.add(tree.create_node('t'), &tree);

    tree.call(&tree, CALLBACKS.print, 0);
    node_t *t = tree.call(&tree, CALLBACKS.search, 't');

    printf("\nFound node is %c.", t->value);

    printf("\nTree height is %d.", tree.height(&tree));
    printf("\nTree size is %d.", tree.size(&tree));

    tree.destroy(&tree);

    return 0;
}