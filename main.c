#include <stdio.h>
#include "tree/tree.h"
#include "callback/callback.h"
#include "strategy/strategy.h"


int main() {
    // Выделили память
    tree_t tree;
    // Инициализировали дерево
    init_tree(&tree);
    // Изменили стратегию обхода (по умолчанию preorder)
    tree.traversal = TRAVERSAL.inorder;
    // Создали и добавили вершины
    tree.add(tree.create_node('r'), &tree);
    tree.add(tree.create_node('o'), &tree);
    tree.add(tree.create_node('o'), &tree);
    tree.add(tree.create_node('t'), &tree);
    // Вывод на печать согласно выбранной стратегии обхода
    tree.call(&tree, CALLBACKS.print, 0);
    // Поиск вершины согласно выбранной стратегии обхода
    node_t *t = tree.call(&tree, CALLBACKS.search, 't');

    printf("\nRoot node is %c.", tree.root->value);
    printf("\nLeft subtree node is %c.", tree.root->left->value);
    printf("\nRight subtree node is %c.", tree.root->right->value);
    printf("\nFound node is %c.", t->value);
    printf("\nTree height is %d.", tree.height(&tree));
    printf("\nTree size is %d.", tree.size(&tree));

    tree.destroy(&tree);

    return 0;
}