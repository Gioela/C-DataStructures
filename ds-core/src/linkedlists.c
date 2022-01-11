#include <stddef.h> // required for NULL
#include <stdlib.h> // required for malloc
#include <stdio.h>  // required for printf
#include "linkedlists.h"

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

list_node_t *list_pop(list_node_t **head)
{
    list_node_t *current_head = *head;
    if (!current_head) return NULL;

    *head = (*head)->next;
    current_head->next = NULL;
    return current_head;
}

string_item_t *list_remove_value(list_node_t **head, const char *value)
// int list_remove(list_node_t **head, const char *value, string_item_t *removed_item)
{
    if (!head) // return NULL;
    {
        printf("[ERR] head is null\n");
        return NULL;
        // return 1;
    }
    if (!value) // return NULL;
    {
        printf("[ERR] value is null\n");
        return NULL;
        // return 1;
    }
    
    string_item_t *current_item = (string_item_t *) head;
    string_item_t *previous_item = NULL;
    // string_item_t *previous_item = current_item;

    // if (current_item->string == value)
    // {
    //     previous_item = current_item;
    //     while (previous_item->node.next)
    //     {
    //         *head = (list_node_t *) previous_item->node.next;
    //         previous_item = previous_item->node.next;
    //     }
    //     current_item->node.next = NULL;
    //     return current_item;
    // }
    
    while (current_item->string != value)
    {
        previous_item = current_item;
        if (!current_item->node.next)
        {
            printf("[ERR] current_item->node.next is null ==> you're arrived to the tail\n");
            // return 1;
            return NULL;
        }
        current_item = current_item->node.next;
    }

    previous_item->node.next = current_item->node.next;
    current_item->node.next = NULL;
    printf("[INFO] removed %s\n", current_item->string);
    return current_item;
    // removed_item = current_item;
    // return 0;
}

string_item_t *string_item_new(const char *string)
{
    string_item_t *item = malloc(sizeof(string_item_t));
    if (!item) return NULL;

    item->string = string;
    return item;
}

int list_run()
{
    string_item_t *my_linked_list = NULL;

    list_append_casted(my_linked_list, "Hello World");
    list_append_casted(my_linked_list, "Test001");
    list_append_casted(my_linked_list, "Test002");
    list_append_casted(my_linked_list, "Last Item of the Linked List");

    puts("[LINKED LIST ELEMENTS]");
    string_item_t *string_item = my_linked_list;
    int idx = 0;
    while (string_item)
    {
        printf("%d. %s\n", idx, string_item->string);
        string_item = (string_item_t *)string_item->node.next;
        ++idx;
    }

    // const char *value_to_remove = "Hello World";                 // TODO Fix bugs!!!
    const char *value_to_remove = "Last Item of the Linked List";
    string_item_t *removed_item = list_remove_value((list_node_t **)my_linked_list, value_to_remove);
    // string_item_t *removed_item = NULL;
    // list_remove((list_node_t **)my_linked_list, (char *)"Test002", removed_item);

    printf("[LINKED LIST AFTER REMOVED ELEMENT] removed element: %s\n", removed_item->string);
    idx = 0;
    string_item = my_linked_list;
    while (string_item)
    {
        printf("%d. %s\n", idx, string_item->string);
        string_item = (string_item_t *)string_item->node.next;
        ++idx;
    }

    // printf("mem_value_to_remove: %s\t-mem_value_removed: %s\n", value_to_remove, removed_item->string);
    return 0;
}