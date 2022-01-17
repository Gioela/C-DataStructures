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
 * Reverse the head list and assign the new item to value
 *
 * @param head List to be reversed
 * @param value Pointer, where the value will be stored
 */
// int list_reverse(list_node_t **head, list_node_t **new_list);
list_node_t *list_reverse(list_node_t **head);

/*
 * Remove the list_node_t element which contains the given value 
 * from the linked list
 *
 * @param **head First element of the linked list
 * @param *value Value which want to remove
 */
string_item_t *list_remove_value(list_node_t **head, const char *value);

/*
 * Remove the list_node_t element at the given index from the linked list
 *
 * @param **head First element of the linked list
 * @param *index Index of the element which want to remove
 */
list_node_t *list_remove_by_index(list_node_t **head, const int index);

/*
 * Initialize new string_item_t structure
 *
 * @param *string String to store into item
 */
string_item_t *string_item_new(const char *string);

/*
 * Print elements which are into linked list
 *
 * @param **head Pointer, list_node_t from which start to print elements
 */
int list_node_print_elements(list_node_t **head);

/*
 * Execute the linkedlists methods: append and remove element
 */
int list_run();

#define _list_node_pointer_twice (list_node_t **)
#define _list_node_pointer_one (list_node_t *)
/*
 * Preprocessor directive: append the pointer to item at the end of the list_node_t list.
 * NOTE: To use the list_append method remember to use pointer casts.
 * 
 * @param list List_node_t object where string_item(next param) must be append
 * @param string_item String which must be append at the end of the previous list_node_t item
 */
#define list_append_casted(list, string_item) list_append(_list_node_pointer_twice &list, _list_node_pointer_one string_item_new(string_item))
