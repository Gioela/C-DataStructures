#include <stddef.h> // required for NULL
#include <stdlib.h> // required for malloc
#include <stdio.h>  // required for printf
#include "linkedlists.h"

// struct list_node *list_get_tail(struct list_node **head)
list_node_t *list_get_tail(list_node_t **head)
{
    list_node_t *current_node = *head;
    list_node_t *last_node = NULL;
    
    while (current_node)
    {
        last_node = current_node;
        current_node = current_node->next;
    }
    return last_node;
}

// struct list_node *list_append(struct list_node **head, struct list_node *item)
list_node_t *list_append(list_node_t **head, list_node_t *item)
{
    list_node_t *tail = list_get_tail(head);
    if (!tail)
    {
        *head = item;
    }
    else
    {
        tail->next = item;
    }
    item->next = NULL;
    return item;
}

// struct list_node *list_pop(struct list_node **head)
list_node_t *list_pop(list_node_t **head)
{
    list_node_t *current_head = *head;
    if (!current_head) return NULL;

    *head = (*head)->next;
    current_head->next = NULL;
    return current_head;
}

// struct string_item *string_item_new(const char *string)
string_item_t *string_item_new(const char *string)
{
    string_item_t *item = malloc(sizeof(string_item_t));
    if (!item) return NULL;

    item->string = string;
    return item;
}

int main()
{
    struct string_item *my_linked_list = NULL;
    list_append((list_node_t **)&my_linked_list, (list_node_t *)string_item_new("Hello World"));
    list_append((list_node_t **)&my_linked_list, (list_node_t *)string_item_new("Test001"));
    list_append((list_node_t **)&my_linked_list, (list_node_t *)string_item_new("Test002"));
    list_append((list_node_t **)&my_linked_list, (list_node_t *)string_item_new("Last Item of the Linked List"));

    struct string_item *string_item = my_linked_list;
    while (string_item)
    {
        printf("%s\n", string_item->string);
        string_item = (struct string_item *)string_item->node.next;
    }
    return 0;
}