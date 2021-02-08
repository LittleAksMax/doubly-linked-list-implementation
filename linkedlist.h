#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "utils.h"

typedef struct node 
{
    int value;
    struct node *next;
    struct node *prev;
} node_t;

node_t *create_node(int);
void show_list(node_t *);

node_t *find_node(node_t *, int);

bool insert_node(node_t *, unsigned int, node_t *);
bool insert_node_head(node_t **, node_t *);
node_t *remove_node(node_t **, node_t *);
void add_node(node_t **, node_t *);

#endif /* _LINKEDLIST_H */