#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

node_t *create_node(int value)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void show_list(node_t *head)
{
    node_t *temp = head;
    printf("NULL - ");
    while (temp != NULL)
    {
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

node_t *find_node(node_t *head, int value)
{
    node_t *temp = head;
    while (temp != NULL)
    {
        if (temp->value == value)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

bool insert_node_head(node_t **head, node_t *node)
{
    if (node == NULL)
        return false;
    node->next = *head;
    if (*head != NULL)
        (*head)->prev = node;
    *head = node;
    return true;
}

bool insert_node(node_t *head, unsigned int index, node_t *node)
{
    if (node == NULL)
        return false;

    int i;
    node_t *temp = head;
    for (i = 0; i < index; i++)
    {
        if (temp == NULL)
            return false;
        temp = temp->next;
    }
    node->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = node;
    temp->next = node;
    node->prev = temp;
    return true;
}

node_t *remove_node(node_t **head, node_t *node)
{
    if (*head == node)
    {
        *head = node->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    } else 
    {
        node->prev->next = node->next;
        if (node->next != NULL)
            node->next->prev = node->prev;
    }
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void add_node(node_t **head, node_t *node)
{
    if (*head == NULL)
    {
        *head = node;
        (*head)->next = NULL;
        (*head)->prev = NULL;
        return;
    }
    node_t *temp = *head;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            node->next = temp->next;
            temp->next = node;
            node->prev = temp;
            return;
        }
        temp = temp->next;
    }
}