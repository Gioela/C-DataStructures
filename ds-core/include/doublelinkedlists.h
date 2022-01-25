#pragma once
#include "linkedlists.h"

// typedef struct dlist_node
// {
//     struct dlist_node *prev;
//     struct dlist_node *next;
// } dlist_node_t;

typedef struct dlist_node
{
    // list_node_t *prev;
    // list_node_t *next;
    struct dlist_node *prev;
    struct dlist_node *next;
} dlist_node_t;

typedef struct dlist_item
{
    dlist_node_t nodes;
    size_t value;
} dlist_item_t;

/* X-T
 * Initialize dlist_node prev and next property to NULL value
 * It returns 0 if success -1 otherwise
 * 
 * @param node Nodes to be initialized
 */
int _dlist_node_initialize(dlist_node_t **node);

/* X-T
 * Return the last dlist_node
 *
 * @param dlist_node dlist_node_t item from which start
 */
dlist_node_t *dlist_get_tail(const dlist_node_t **head);

/* X-T
 * Append dlist_node to head dlist_node's tail
 *
 * @param head dlist_node_t item from which start
 * @param item dlist_node_t to attach at the tail of head's nodes
 */
dlist_node_t *dlist_append(dlist_node_t **head, dlist_node_t *node);

/* X-T
 * Initialize dlist_item
 *
 * @param value Value must be assigned to the item (item->value)
 * @param item Return item valorizated
 */
int dlist_item_new(const size_t *value, dlist_item_t **item);

/*X-T
 * Clear and free the memory occupied by the dlist_item_t
 *
 * @param dlist_node Item which want to clear
 */
int dlist_item_clear(dlist_item_t *item);

/* X-T
 * Returns the value of dlst_item_t value property
 *
 * @param item Item from which you want to get the value of property "value"
 */
size_t dlist_get_value(const dlist_item_t *item);


dlist_item_t *dlist_search_by_value(dlist_item_t **head, const size_t *value, int *position);

/*
 * Search and remove an item by value from given double linked list
 *
 * @param value Value's item which want to remove
 * @param head Head of the double linked list
 */
dlist_item_t *dlist_item_remove_by_value(const size_t *value, dlist_item_t **head);

/*
 * Print the list of the value's elements in dlinked_list
 *
 * @param head First Item which want to start
 */
int dlist_print(const dlist_item_t *head);