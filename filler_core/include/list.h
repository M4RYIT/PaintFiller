#pragma once

#include <stdlib.h>
#include <stdint.h>

typedef struct l_node
{
    struct l_node *next;
    uint8_t *value;
}
l_node;

typedef struct
{
    l_node *head;
    size_t type;
}
list;

void list_init(list *l, const size_t t);

void list_append(list *l, const void *value);

int list_empty(list *l);

void list_pop(list *l, void *value);

l_node *l_node_last(l_node *head);

void l_node_init(l_node **node, const size_t t, const void *value);

void l_node_clear(l_node **node);