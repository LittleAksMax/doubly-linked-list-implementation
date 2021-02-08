#include <stdio.h>
#include "linkedlist.h"

typedef struct {
    double x, y;
} Node;

int main()
{
    node_t *head = create_node(5);

    add_node(&head, create_node(10));
    add_node(&head, create_node(15));
    add_node(&head, create_node(20));
    int good = insert_node(head, 2, create_node(25));
    show_list(head);
    
    return 0;
}