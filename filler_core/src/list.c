#include <stdio.h>
#include <string.h>
#include "list.h"

void list_init(list *l, const size_t t)
{
    l->type = t;
    l->head = NULL;
}

void list_append(list *l, const void *value)
{
    if (list_empty(l))
    {
        l_node_init(&l->head, l->type, value);
        return;
    }

    l_node_init(&(l_node_last(l->head)->next), l->type, value);
}

int list_empty(list *l)
{
    if (!l->head) return -1;
    return 0;
}

void list_pop(list *l, void *value)
{   
    if (list_empty(l)) return; 

    l_node *new_head = l->head->next;
    memcpy(value, l->head->value, l->type);
    l_node_clear(&l->head);
    l->head = new_head;
}

l_node *l_node_last(l_node *head)
{
    l_node *current = head;
    l_node *n;

    while(current)
    {
        n = current;
        current = current->next;
    }

    return n;
}

void l_node_init(l_node **node, const size_t t, const void *value)
{
    *node = malloc(sizeof(l_node));

    (*node)->value = malloc(t);

    memcpy((*node)->value, value, t);

    (*node)->next = NULL;
}

void l_node_clear(l_node **node)
{
    free((*node)->value);
    (*node)->value = NULL;
    (*node)->next = NULL;
}