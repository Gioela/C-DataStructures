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
    if (!current_head)
        return NULL;

    *head = (*head)->next;
    current_head->next = NULL;
    return current_head;
}

// int list_reverse(list_node_t **head, list_node_t **new_list)
list_node_t *list_reverse(list_node_t **head)
{
    // if (!*head) return -1;
    if (!*head)
        return NULL;

    list_node_t *cur_node = *head;
    list_node_t *last_node = NULL;
    list_node_t *temp_node = NULL;
    list_node_print_elements((list_node_t **)head);

    while (cur_node)
    {
        temp_node = cur_node->next;
        cur_node->next = last_node;
        last_node = cur_node;
        cur_node = temp_node;
    }
    
    // *head = last_node;
    puts("- - --< 0.0 >-- - -");
    // in this case it prints only first two elements
    list_node_print_elements((list_node_t **)head);
    
    puts("--< 0.1 >--");
    // in this case it prints, like 1st element (null) and lost the last(original 1st) element... WHY?!
    list_node_print_elements((list_node_t **)&last_node);
    
    puts("- - --< 0.0 >-- - -");
    
    return last_node;
}

list_node_t *list_remove_by_index(list_node_t **head, const int index)
{
    list_node_t *result_node = NULL;
    int int_index = index;

    printf("\nindex: %d\n\n", int_index);

    if (*head == NULL || int_index < 0)
    {
        return result_node;
    }

    if (int_index == 0)
    {
        return list_pop((list_node_t **)&head);
        // printf("must be removed index zero => ");
        // string_item_t *node = (string_item_t *) list_pop((list_node_t **)&head);
        // printf("node_string_element: %s\n", node->string);
        // return (list_node_t *)node;
    }
        
    int start_position = 0;
    list_node_t *temp_node = *head;
    list_node_t *old_node = NULL;

    while (temp_node->next)
    {
        printf("cycle: %d  - index: %d", start_position, int_index);
        printf("  - element: %s\n", ((string_item_t *)temp_node)->string);
        old_node = temp_node;

        if (start_position == int_index)
        {
            puts("return the element at the index position");
            result_node = temp_node;
            result_node->next = NULL;
            old_node->next = temp_node->next;
            break;
        }
        temp_node = temp_node->next;
        ++start_position;
    }

    *head = temp_node;

    // if (start_position > int_index)
    // {
    //     /* */
    // }
    
    return result_node;
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
    
    if (((string_item_t *)head)->string == value)
    {
        // string_item_t *popped = (string_item_t *)list_pop((list_node_t **)&head);
        // return popped;
        return (string_item_t *)list_pop((list_node_t **)&head);
    }
    
    string_item_t *current_item = (string_item_t *)head;
    string_item_t *previous_item = NULL;

    while (current_item->string != value)
    {
        previous_item = current_item;
        if (!current_item->node.next)
        {
            printf("[ERR] current_item->node.next is null ==> you're arrived to the tail\n");
            // return 1;
            return NULL;
        }
        current_item = (string_item_t *)current_item->node.next;
    }

    previous_item->node.next = current_item->node.next;
    current_item->node.next = NULL;
    printf("[INFO] removed: %s\n", current_item->string);
    return current_item;
    // return 0;
}

string_item_t *string_item_new(const char *string)
{
    string_item_t *item = malloc(sizeof(string_item_t));
    if (!item)
        return NULL;

    item->string = string;
    return item;
}

int list_node_print_elements(list_node_t **head)
{
    if (!*head) return -1;
    printf("print list_node_t elements\n");

    string_item_t *list_items = (string_item_t *)head;

    int idx = 0;
    while (list_items)
    {
        printf("%d. %s\n", idx, list_items->string);
        list_items = (string_item_t *)list_items->node.next;
        ++idx;
    }

    return 0;
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