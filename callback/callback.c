#include <stdio.h>
#include "callback.h"

void * print_callback(node_t *node, T key) {
    if ( node->value ) printf("%c ", node->value);
    return NULL;
}
void * search_callback(node_t *node, T key) {
    if ( key == node->value ) {
        return node;
    } else {
        return NULL;
    }
}

callback_t CALLBACKS = {
        &print_callback,
        &search_callback
};
