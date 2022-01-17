#pragma once
#include "clove.h"
#include "linkedlists.h"

CLOVE_TEST(linked_list_new_string_item_t)
{
    int size_string_item = sizeof(string_item_t);

    string_item_t *new_string = string_item_new("Hello World");

    CLOVE_INT_EQ(size_string_item, sizeof(*new_string));
    free(new_string);
}

CLOVE_TEST(linked_list_get_tail)
{
    list_node_t *list_node = NULL;

    list_append_casted(list_node, "first");
    list_append_casted(list_node, "second");
    list_node_t *node_tail = list_append_casted(list_node, "tail");

    list_node_t *list_tail = list_get_tail((list_node_t **)list_node);

    CLOVE_NULL(list_tail->next);
    CLOVE_PTR_EQ(list_tail, node_tail);
}

CLOVE_TEST(linked_list_append_1_string_item_t)
{
    string_item_t *list_items = NULL;

    list_node_t *list_node_01 = list_append_casted(list_items, "Test000");
    
    CLOVE_NULL(list_items->node.next);
    CLOVE_IS_TRUE(list_items->string == ((string_item_t *)list_node_01)->string);
}

CLOVE_TEST(linked_list_append_1_string_item_t_err)
{
    string_item_t *list_items = NULL;

    list_node_t *list_node_01 = list_append_casted(list_items, "Test000");
    // list_node_t *list_node_02 = list_append_casted(list_items, "test02");

    // list_node_print_elements(list_items);

    list_node_t *tail_list = list_get_tail((list_node_t **)&list_items);
    list_node_t *node = list_pop((list_node_t **)&list_items);
    
    // CLOVE_NULL(list_items->node.next);
    // puts("----");
    CLOVE_NULL(tail_list->next);
    CLOVE_PTR_EQ(node, list_node_01);
    CLOVE_IS_TRUE(((string_item_t *)node)->string == ((string_item_t *)list_node_01)->string);
}

CLOVE_TEST(linked_list_append_3_string_item_t)
{
    string_item_t *list_items = NULL;

    string_item_t *item_00 = string_item_new("item_0");
    string_item_t *item_01 = string_item_new("item_1");
    string_item_t *item_02 = string_item_new("item_2");

    list_node_t *node_00 = list_append((list_node_t **)&list_items, (list_node_t *) item_00);
    list_node_t *node_01 = list_append((list_node_t **)&list_items, (list_node_t *) item_01);
    list_node_t *node_02 = list_append((list_node_t **)&list_items, (list_node_t *) item_02);

    CLOVE_PTR_EQ((list_node_t *)item_00, list_pop((list_node_t **)&list_items));
    CLOVE_PTR_EQ((list_node_t *)item_01, list_pop((list_node_t **)&list_items));
    CLOVE_PTR_EQ((list_node_t *)item_02, list_pop((list_node_t **)&list_items));
}

CLOVE_TEST(linked_list_reverse)
{
    string_item_t *list_items = NULL;
    
    string_item_t *v00 = string_item_new("v_00");
    string_item_t *v01 = string_item_new("v_01");
    string_item_t *v02 = string_item_new("v_02");
    string_item_t *v03 = string_item_new("v_03");

    list_node_t *element_00 = list_append((list_node_t **)&list_items, (list_node_t *)v00);
    list_node_t *element_01 = list_append((list_node_t **)&list_items, (list_node_t *)v01);
    list_node_t *element_02 = list_append((list_node_t **)&list_items, (list_node_t *)v02);
    list_node_t *element_03 = list_append((list_node_t **)&list_items, (list_node_t *)v03);
    // list_node_t *element_00 = list_append_casted(list_items, "value_00");
    // list_node_t *element_01 = list_append_casted(list_items, "value_01");
    // list_node_t *element_02 = list_append_casted(list_items, "value_02");
    // list_node_t *element_03 = list_append_casted(list_items, "value_03");
    list_node_print_elements((list_node_t **) list_items);


puts(" --- 02 ---");
    // int result = list_reverse((list_node_t **)list_items, (list_node_t **)new_list_items);
    list_node_t *result = list_reverse((list_node_t **)list_items);

puts(" --- 03 ---");
    list_node_print_elements((list_node_t **)result);

    CLOVE_PTR_EQ(list_pop((list_node_t **)&result), element_03);
    CLOVE_PTR_EQ(list_pop((list_node_t **)&result), element_02);
    CLOVE_PTR_EQ(list_pop((list_node_t **)&result), element_01);
    CLOVE_PTR_EQ(list_pop((list_node_t **)&result), element_00);
}

CLOVE_TEST(linked_list_remove_first_value)
{
    string_item_t *list_items = NULL;

    list_append_casted(list_items, "Hello World");
    list_append_casted(list_items, "Test001");
    list_append_casted(list_items, "Test002");
    list_append_casted(list_items, "Last Item of the Linked List");

    const char *value_to_remove = "Hello World";
    string_item_t *removed_item = NULL;
    removed_item = list_remove_value((list_node_t **)list_items, value_to_remove);

    // printf("list_items->string: %s\n", list_items->string);
    // list_node_print_elements((list_node_t *)&list_items);
    // printf("removed->string: %s\n", removed_item->string);
    // list_node_print_elements((list_node_t *)&removed_item);
    
    CLOVE_IS_TRUE(value_to_remove== removed_item->string);
}

CLOVE_TEST(linked_list_remove_middle_value)
{
    string_item_t *list_items = NULL;

    list_append_casted(list_items, "Hello World");
    list_append_casted(list_items, "Test001");
    list_append_casted(list_items, "Test002");
    list_append_casted(list_items, "Last Item of the Linked List");

    const char *value_to_remove = "Test002";
    string_item_t *removed_item = NULL;
    removed_item = list_remove_value((list_node_t **)list_items, value_to_remove);

    // list_node_print_elements((list_node_t **)list_items);
    CLOVE_IS_TRUE(value_to_remove == removed_item->string);
}

CLOVE_TEST(linked_list_remove_tail_value)
{
    string_item_t *list_items = NULL;

    list_append_casted(list_items, "Hello World");
    list_append_casted(list_items, "Test001");
    list_append_casted(list_items, "Test002");
    list_append_casted(list_items, "Last Item of the Linked List");

    const char *value_to_remove = "Last Item of the Linked List";
    string_item_t *removed_item = NULL;
    removed_item = list_remove_value((list_node_t **)list_items, value_to_remove);

    // list_node_print_elements((list_node_t **)list_items);
    CLOVE_IS_TRUE(value_to_remove == removed_item->string);
}

CLOVE_TEST(linked_list_remove_by_index_zero)
{
    list_node_t *list_node = NULL;
    list_node_t *result_node = NULL;

    string_item_t *value_00 = string_item_new("value_00");
    string_item_t *value_01 = string_item_new("value_01");
    string_item_t *value_02 = string_item_new("value_02");
    string_item_t *value_03 = string_item_new("value_03");

    list_node_t *node_00 = list_append((list_node_t **)&list_node, (list_node_t *)value_00);
    list_node_t *node_01 = list_append((list_node_t **)&list_node, (list_node_t *)value_01);
    list_node_t *node_02 = list_append((list_node_t **)&list_node, (list_node_t *)value_02);
    list_node_t *node_03 = list_append((list_node_t **)&list_node, (list_node_t *)value_03);
    
    list_node_print_elements((list_node_t **)list_node);
    
    int zero_index = 0;
    result_node = list_remove_by_index((list_node_t **)list_node, zero_index);
    
    printf("AFTER ----> ");
    list_node_print_elements((list_node_t **)&list_node);

    CLOVE_PTR_EQ(node_00, result_node);
}

CLOVE_TEST(linked_list_remove_by_negative_index)
{
    list_node_t *list_node = NULL;
    list_node_t *result_node = NULL;

    string_item_t *value_00 = string_item_new("value_00");
    string_item_t *value_01 = string_item_new("value_01");
    string_item_t *value_02 = string_item_new("value_02");
    string_item_t *value_03 = string_item_new("value_03");

    list_node_t *node_00 = list_append((list_node_t **)&list_node, (list_node_t *)value_00);
    list_node_t *node_01 = list_append((list_node_t **)&list_node, (list_node_t *)value_01);
    list_node_t *node_02 = list_append((list_node_t **)&list_node, (list_node_t *)value_02);
    list_node_t *node_03 = list_append((list_node_t **)&list_node, (list_node_t *)value_03);
    
    list_node_print_elements((list_node_t **)list_node);

    int negative = -1;

    result_node = list_remove_by_index((list_node_t **)list_node, negative);
    CLOVE_NULL(result_node);
}

CLOVE_TEST(linked_list_remove_by_index)
{
    list_node_t *list_node = NULL;
    list_node_t *result_node = NULL;
    int index = 2;

    string_item_t *value_00 = string_item_new("value_00");
    string_item_t *value_01 = string_item_new("value_01");
    string_item_t *value_02 = string_item_new("value_02");
    string_item_t *value_03 = string_item_new("value_03");

    list_node_t *node_00 = list_append((list_node_t **)&list_node, (list_node_t *)value_00);
    list_node_t *node_01 = list_append((list_node_t **)&list_node, (list_node_t *)value_01);
    list_node_t *node_02 = list_append((list_node_t **)&list_node, (list_node_t *)value_02);
    list_node_t *node_03 = list_append((list_node_t **)&list_node, (list_node_t *)value_03);
    
    list_node_print_elements((list_node_t **)list_node);
    
    result_node = list_remove_by_index((list_node_t **)list_node, index);
    
    printf("AFTER ----> ");
    list_node_print_elements((list_node_t **)&list_node);

    CLOVE_PTR_EQ(node_02, result_node);
}

CLOVE_TEST(linked_list_pop_element)
{
    list_node_t *list_node = NULL;
    list_node_t *result_node = NULL;

    string_item_t *value_00 = string_item_new("value_00");
    string_item_t *value_01 = string_item_new("value_01");
    string_item_t *value_02 = string_item_new("value_02");
    string_item_t *value_03 = string_item_new("value_03");

    list_node_t *node_00 = list_append((list_node_t **)&list_node, (list_node_t *)value_00);
    list_node_t *node_01 = list_append((list_node_t **)&list_node, (list_node_t *)value_01);
    list_node_t *node_02 = list_append((list_node_t **)&list_node, (list_node_t *)value_02);
    list_node_t *node_03 = list_append((list_node_t **)&list_node, (list_node_t *)value_03);
    
    printf("LIST_NODE before pop -> ");
    list_node_print_elements((list_node_t **)list_node);

    result_node = list_pop((list_node_t **)&list_node);

    printf("LIST_NODE after pop -> ");
    list_node_print_elements((list_node_t **)list_node);
    printf("RESULT_NODE popped -> ");
    list_node_print_elements((list_node_t **)&result_node);

    CLOVE_NULL(result_node->next);
    CLOVE_IS_TRUE(((string_item_t *)result_node)->string == value_00->string);

    list_node_t *popped_node = NULL;
    
    popped_node = list_pop((list_node_t **)&list_node);
    CLOVE_PTR_EQ(popped_node, node_01);

    popped_node = list_pop((list_node_t **)&list_node);
    CLOVE_PTR_EQ(popped_node, node_02);
    
    popped_node = list_pop((list_node_t **)&list_node);
    CLOVE_PTR_EQ(popped_node, node_03);
}