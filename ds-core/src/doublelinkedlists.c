#include <stdio.h>
#include <stddef.h> // required for NULL
#include <stdlib.h> // required for malloc
// #include "linkedlists.h"
#include "doublelinkedlists.h"

int _dlist_node_initialize(dlist_node_t **node)
{
    // dlist_node_t *_node = NULL;
    // if (!*node)
    // {
    //     puts("test");
    //     _node = malloc(sizeof(dlist_node_t));
    //     if (!_node) return -1;    
    // }
    // else
    // {
    //     puts("nodes maybe are allocated");
    // }
    
    dlist_node_t *_node = malloc(sizeof(dlist_node_t));
    if (!_node) return -1;    

    _node->next = NULL;
    _node->prev = NULL;
    
    *node = _node;
    return 0;
}

dlist_node_t *dlist_get_tail(const dlist_node_t **head)
{
    dlist_node_t *current_node = *head;
    dlist_node_t *tail = NULL;

    while (current_node)
    {
        tail = current_node;
        current_node = current_node->next;
    }

    return tail;
}

dlist_node_t *dlist_append(dlist_node_t **head, dlist_node_t *node)
{
    dlist_node_t *tail = dlist_get_tail(head);
    if (!tail)
        *head = node;
    else
        tail->next = node;
    node->prev = tail;
    node->next = NULL;
    return node;
}

size_t dlist_get_value(const dlist_item_t *item)
{
    return item->value;
}

int dlist_item_new(const size_t *value, dlist_item_t **item)
{
    dlist_item_t *_item = malloc(sizeof(dlist_item_t));
    if (!_item) return -1;
    
    int res = _dlist_node_initialize( (dlist_node_t **)&_item->nodes);
    if (res != 0) return -1;

    _item->value = *value;
    *item = _item;
    return 0;
}

int dlist_item_clear(dlist_item_t *item)
{
    item->value = NULL;
    // free(item->value);
    item->nodes.prev = NULL;
    item->nodes.next = NULL;
    // free((dlist_node_t *)&item->nodes);
    free(item);
    return 0;
}


dlist_item_t *dlist_search_by_value(dlist_item_t **head, const size_t *value, int *position)
{
    dlist_item_t *current_item = *head;
    dlist_item_t *item = NULL;
    int pos = 0;

    while (current_item)
    {
        if (current_item->value == *value)
        {
            item = current_item;
            *position = pos;
        }
        current_item = (dlist_item_t *) current_item->nodes.next;
        ++pos;
    }
    
    return item;
}

dlist_item_t *dlist_item_remove_by_value(const size_t *value, dlist_item_t **head)
{
    dlist_item_t *result_item = *head;

    if ((*head)->value == *value) 
    {
        *head = (*head)->nodes.next;
        (*head)->nodes.prev = NULL;
        result_item->nodes.next=NULL;
        return result_item;
    }
    
    result_item = (dlist_item_t *)dlist_get_tail((dlist_node_t **)&result_item);
    if (result_item->value == *value)
    {
        result_item->nodes.prev->next = NULL;
        result_item->nodes.prev = NULL;
        return result_item;
    }

    int value_position = -1;
    result_item = dlist_search_by_value(head, value, &value_position);
    if(!result_item) return NULL;

    result_item->nodes.prev->next = result_item->nodes.next;
    result_item->nodes.next->prev = result_item->nodes.prev;
    result_item->nodes.prev = NULL;
    result_item->nodes.next = NULL;

    return result_item;
}

int dlist_print(const dlist_item_t *head)
{
    if (!head) return -1;
    
    dlist_item_t *current_node = head;
    int position = 0;

    printf("Here the list of the value's elements in dlinked_list:\n");
    while (current_node)
    {
        // printf("%d. %zu\n", position, current_node->value);
        printf("%d. %d\n", position, current_node->value);
        current_node = (dlist_item_t *)current_node->nodes.next;
        ++position;
    }
    
    return 0;
}