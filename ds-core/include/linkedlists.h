#pragma once


typedef struct list_node
{
    struct list_node *next;
} list_node_t;

typedef struct string_item
{
    struct list_node node;
    const char *string;
} string_item_t;

/*
 * Returns the tail of the list node
 *
 * @param **head First element from which starts to get tail
 */
list_node_t *list_get_tail(list_node_t **head);

/*
 * Append item to the tail of linked list
 *
 * @param **head First element of the linked list
 * @param *item Item which wants to insert at the end of the linked list
 */
list_node_t *list_append(list_node_t **head, list_node_t *item);

/*
 * Remove last element from the linked list and returns it
 *
 * @param **head First element of the linked list
 */
list_node_t *list_pop(list_node_t **head);

/*
 * Initialize new string_item_t structure
 *
 * @param *string String to store into item
 */
string_item_t *string_item_new(const char *string);

// struct list_node *list_get_tail(struct list_node **head);
// struct list_node *list_append(struct list_node **head, struct list_node *item);
// struct list_node *list_pop(struct list_node **head);
// struct string_item *string_item_new(const char *string);
