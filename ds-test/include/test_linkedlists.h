#pragma once
#include "clove.h"
#include "linkedlists.h"

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

    CLOVE_IS_TRUE(value_to_remove == removed_item->string);
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

    CLOVE_IS_TRUE(value_to_remove == removed_item->string);
}