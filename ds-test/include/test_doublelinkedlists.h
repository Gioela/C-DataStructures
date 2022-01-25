#pragma once
#include "clove.h"
#include "doublelinkedlists.h"

CLOVE_TEST(doublelinkedlists_node_initializer)
{
    dlist_node_t *node = NULL;

    int result;
    result = _dlist_node_initialize((dlist_node_t **)&node);

    CLOVE_INT_EQ(0, result);
    CLOVE_NULL(node->next);
    CLOVE_NULL(node->prev);
    free(node);
}

CLOVE_TEST(doublelinkedlists_new_item)
{
    int result = -9;
    int value = 33;
    dlist_item_t *item=NULL;
    result = dlist_item_new(&value, (dlist_item_t **)&item);
    CLOVE_INT_EQ(0, result);
    CLOVE_INT_EQ(value, item->value);
    CLOVE_INT_EQ(0, dlist_item_clear(item));
}

CLOVE_TEST(doublelinkedlists_get_item_value)
{
    int result = -9;
    int value = 33;
    dlist_item_t *item=NULL;
    result = dlist_item_new(&value, (dlist_item_t **)&item);

    CLOVE_INT_EQ(0, result);
    CLOVE_INT_EQ(value, dlist_get_value(item));
    CLOVE_INT_EQ(0, dlist_item_clear(item));
}

CLOVE_TEST(doublelinkedlists_append_three_nodes)
{
    int value_01 = 33;
    int value_02 = 43;
    int value_03 = 53;
    dlist_item_t *item_01=NULL;
    dlist_item_t *item_02=NULL;
    dlist_item_t *item_03=NULL;

    int result = dlist_item_new(&value_01, (dlist_item_t **)&item_01);
    result = dlist_item_new(&value_02, (dlist_item_t **)&item_02);    
    result = dlist_item_new(&value_03, (dlist_item_t **)&item_03);

    dlist_node_t *root_node = NULL;
    dlist_node_t *node_01 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_01->nodes );
    dlist_node_t *node_02 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_02->nodes );
    dlist_node_t *node_03 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_03->nodes );

    CLOVE_PTR_EQ((dlist_node_t *)&item_01->nodes, node_01);
    CLOVE_PTR_EQ((dlist_node_t *)&item_02->nodes, node_02);
    CLOVE_PTR_EQ((dlist_node_t *)&item_03->nodes, node_03);

    dlist_item_clear(item_01);
    dlist_item_clear(item_02);
    dlist_item_clear(item_03);
}

CLOVE_TEST(doublelinkedlists_free_item_memory)
{
    int result = -9;
    int value = 33;
    dlist_item_t *item=NULL;

    result = dlist_item_new(&value, (dlist_item_t **)&item);
    CLOVE_INT_EQ(0, result);

    result = dlist_item_clear(item);
    CLOVE_INT_EQ(0, result);
}

CLOVE_TEST(doublelinkedlists_get_tail_node)
{
    int value_01 = 33;
    int value_02 = 43;
    int value_03 = 53;
    dlist_item_t *item_01=NULL;
    dlist_item_t *item_02=NULL;
    dlist_item_t *item_03=NULL;

    int result = dlist_item_new(&value_01, (dlist_item_t **)&item_01);
    result = dlist_item_new(&value_02, (dlist_item_t **)&item_02);
    result = dlist_item_new(&value_03, (dlist_item_t **)&item_03);

    dlist_node_t *root_node = NULL;
    dlist_node_t *node_01 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_01->nodes );
    dlist_node_t *node_02 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_02->nodes );
    dlist_node_t *node_03 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_03->nodes );

    dlist_node_t *tail = dlist_get_tail((dlist_node_t **)&root_node);
    CLOVE_INT_EQ(value_03, ((dlist_item_t *)tail)->value);
    CLOVE_PTR_EQ(tail, node_03);
    CLOVE_PTR_EQ(tail, (dlist_node_t *)&item_03->nodes);

    dlist_item_clear(item_01);
    dlist_item_clear(item_02);
    dlist_item_clear(item_03);
}

CLOVE_TEST(doublelinkedlists_remove_by_value)
{
    int value_01 = 13;
    int value_02 = 23;
    int value_03 = 33;
    int value_04 = 43;
    int value_05 = 53;
    int value_06 = 63;
    int value_07 = 73;
    dlist_item_t *item_01=NULL;
    dlist_item_t *item_02=NULL;
    dlist_item_t *item_03=NULL;
    dlist_item_t *item_04=NULL;
    dlist_item_t *item_05=NULL;
    dlist_item_t *item_06=NULL;
    dlist_item_t *item_07=NULL;

    int result = dlist_item_new(&value_01, (dlist_item_t **)&item_01);
    result = dlist_item_new(&value_02, (dlist_item_t **)&item_02);
    result = dlist_item_new(&value_03, (dlist_item_t **)&item_03);
    result = dlist_item_new(&value_04, (dlist_item_t **)&item_04);
    result = dlist_item_new(&value_05, (dlist_item_t **)&item_05);
    result = dlist_item_new(&value_06, (dlist_item_t **)&item_06);
    result = dlist_item_new(&value_07, (dlist_item_t **)&item_07);

    dlist_node_t *root_node = NULL;
    dlist_node_t *node_01 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_01->nodes );
    dlist_node_t *node_02 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_02->nodes );
    dlist_node_t *node_03 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_03->nodes );
    dlist_node_t *node_04 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_04->nodes );
    dlist_node_t *node_05 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_05->nodes );
    dlist_node_t *node_06 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_06->nodes );
    dlist_node_t *node_07 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_07->nodes );

    dlist_item_t *item_removed = dlist_item_remove_by_value((size_t *)&value_05, (dlist_item_t **)&root_node);

    CLOVE_PTR_EQ(node_04->next, node_06);
    CLOVE_PTR_EQ(node_06->prev, node_04);
    CLOVE_NULL(item_removed->nodes.prev);
    CLOVE_NULL(item_removed->nodes.next);

    dlist_item_clear(item_01);
    dlist_item_clear(item_02);
    dlist_item_clear(item_03);
    dlist_item_clear(item_04);
    dlist_item_clear(item_05);
    dlist_item_clear(item_06);
    dlist_item_clear(item_07);
}

CLOVE_TEST(doublelinkedlists_remove_last_value)
{
    int value_01 = 13;
    int value_02 = 23;
    int value_03 = 33;
    int value_04 = 43;
    dlist_item_t *item_01=NULL;
    dlist_item_t *item_02=NULL;
    dlist_item_t *item_03=NULL;
    dlist_item_t *item_04=NULL;

    int result = dlist_item_new(&value_01, (dlist_item_t **)&item_01);
    result = dlist_item_new(&value_02, (dlist_item_t **)&item_02);
    result = dlist_item_new(&value_03, (dlist_item_t **)&item_03);
    result = dlist_item_new(&value_04, (dlist_item_t **)&item_04);

    dlist_node_t *root_node = NULL;
    dlist_node_t *node_01 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_01->nodes );
    dlist_node_t *node_02 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_02->nodes );
    dlist_node_t *node_03 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_03->nodes );
    dlist_node_t *node_04 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_04->nodes );

    dlist_item_t *item_removed = dlist_item_remove_by_value((size_t *)&value_04, (dlist_item_t **)&root_node);

    CLOVE_NULL(node_03->next);
    CLOVE_NULL(item_removed->nodes.prev);
    CLOVE_NULL(item_removed->nodes.next);

    CLOVE_NULL(node_04->prev);
    CLOVE_NULL(node_04->next);

    dlist_item_clear(item_01);
    dlist_item_clear(item_02);
    dlist_item_clear(item_03);
    dlist_item_clear(item_04);
}

CLOVE_TEST(doublelinkedlists_remove_first_value)
{
    int value_01 = 13;
    int value_02 = 23;
    int value_03 = 33;
    dlist_item_t *item_01=NULL;
    dlist_item_t *item_02=NULL;
    dlist_item_t *item_03=NULL;

    int result = dlist_item_new(&value_01, (dlist_item_t **)&item_01);
    result = dlist_item_new(&value_02, (dlist_item_t **)&item_02);
    result = dlist_item_new(&value_03, (dlist_item_t **)&item_03);

    dlist_node_t *root_node = NULL;
    dlist_node_t *node_01 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_01->nodes );
    dlist_node_t *node_02 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_02->nodes );
    dlist_node_t *node_03 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_03->nodes );
    
    dlist_item_t *item_removed = dlist_item_remove_by_value((size_t *)&value_01, (dlist_item_t **)&root_node);

    CLOVE_NULL(node_01->prev);
    CLOVE_NULL(node_01->next);
    CLOVE_NULL(item_removed->nodes.prev);
    CLOVE_NULL(item_removed->nodes.next);

    CLOVE_NULL(node_02->prev);
    CLOVE_NOT_NULL(node_02->next);

    dlist_item_clear(item_01);
    dlist_item_clear(item_02);
    dlist_item_clear(item_03);
}

CLOVE_TEST(doublelinkedlists_insert_before)
{
    int value_01 = 13;
    int value_02 = 23;
    int value_03 = 33;
    int value_04 = 43;
    dlist_item_t *item_01=NULL;
    dlist_item_t *item_02=NULL;
    dlist_item_t *item_03=NULL;
    dlist_item_t *item_04=NULL;

    // initialize new items
    int result = dlist_item_new(&value_01, (dlist_item_t **)&item_01);
    result = dlist_item_new(&value_02, (dlist_item_t **)&item_02);
    result = dlist_item_new(&value_03, (dlist_item_t **)&item_03);
    result = dlist_item_new(&value_04, (dlist_item_t **)&item_04);

    dlist_node_t *root_node = NULL;
    dlist_node_t *node_01 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_01->nodes );
    dlist_node_t *node_02 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_02->nodes );
    dlist_node_t *node_03 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_03->nodes );

    // insert node_04 before node_03
    result = dlist_insert_before((dlist_node_t *)&item_04->nodes, (dlist_node_t *)&item_03->nodes);
    
    CLOVE_INT_EQ(0, result);
    CLOVE_PTR_EQ(item_04->nodes.next, node_03);
    CLOVE_PTR_EQ(item_04->nodes.prev, node_02);
    CLOVE_PTR_EQ(node_02->next, (dlist_node_t *)&item_04->nodes);
    CLOVE_PTR_EQ(node_03->prev, (dlist_node_t *)&item_04->nodes);

    dlist_item_clear(item_01);
    dlist_item_clear(item_02);
    dlist_item_clear(item_03);
    dlist_item_clear(item_04);
}

CLOVE_TEST(doublelinkedlists_insert_NULL_before_node)
{
    int value_01 = 13;
    int value_02 = 23;
    int value_03 = 33;
    int value_04 = 43;
    dlist_item_t *item_01=NULL;
    dlist_item_t *item_02=NULL;
    dlist_item_t *item_03=NULL;
    dlist_item_t *item_04=NULL;

    // initialize new items
    int result = dlist_item_new(&value_01, (dlist_item_t **)&item_01);
    result = dlist_item_new(&value_02, (dlist_item_t **)&item_02);
    result = dlist_item_new(&value_03, (dlist_item_t **)&item_03);
    result = dlist_item_new(&value_04, (dlist_item_t **)&item_04);

    dlist_node_t *root_node = NULL;
    dlist_node_t *node_01 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_01->nodes );
    dlist_node_t *node_02 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_02->nodes );
    dlist_node_t *node_03 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_03->nodes );

    // insert NULL before node_03
    result = dlist_insert_before((dlist_node_t *)NULL, (dlist_node_t *)&item_03->nodes);
    
    CLOVE_INT_EQ(-1, result);

    dlist_item_clear(item_01);
    dlist_item_clear(item_02);
    dlist_item_clear(item_03);
    dlist_item_clear(item_04);
}

CLOVE_TEST(doublelinkedlists_insert_node_before_NULL)
{
    int value_01 = 13;
    int value_02 = 23;
    int value_03 = 33;
    int value_04 = 43;
    dlist_item_t *item_01=NULL;
    dlist_item_t *item_02=NULL;
    dlist_item_t *item_03=NULL;
    dlist_item_t *item_04=NULL;

    // initialize new items
    int result = dlist_item_new(&value_01, (dlist_item_t **)&item_01);
    result = dlist_item_new(&value_02, (dlist_item_t **)&item_02);
    result = dlist_item_new(&value_03, (dlist_item_t **)&item_03);
    result = dlist_item_new(&value_04, (dlist_item_t **)&item_04);

    dlist_node_t *root_node = NULL;
    dlist_node_t *node_01 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_01->nodes );
    dlist_node_t *node_02 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_02->nodes );
    dlist_node_t *node_03 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_03->nodes );

    // insert node_04 before NULL
    result = dlist_insert_before((dlist_node_t *)&item_04->nodes, (dlist_node_t *)NULL);
    
    CLOVE_INT_EQ(-1, result);

    dlist_item_clear(item_01);
    dlist_item_clear(item_02);
    dlist_item_clear(item_03);
    dlist_item_clear(item_04);
}

CLOVE_TEST(doublelinkedlists_insert_after)
{
    int value_01 = 13;
    int value_02 = 23;
    int value_03 = 33;
    int value_04 = 43;
    dlist_item_t *item_01=NULL;
    dlist_item_t *item_02=NULL;
    dlist_item_t *item_03=NULL;
    dlist_item_t *item_04=NULL;

    // initialize new items
    int result = dlist_item_new(&value_01, (dlist_item_t **)&item_01);
    result = dlist_item_new(&value_02, (dlist_item_t **)&item_02);
    result = dlist_item_new(&value_03, (dlist_item_t **)&item_03);
    result = dlist_item_new(&value_04, (dlist_item_t **)&item_04);

    dlist_node_t *root_node = NULL;
    dlist_node_t *node_01 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_01->nodes );
    dlist_node_t *node_02 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_02->nodes );
    dlist_node_t *node_03 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_03->nodes );

    // insert node_04 after node_03
    result = dlist_insert_after((dlist_node_t *)&item_04->nodes, (dlist_node_t *)&item_02->nodes);
    
    CLOVE_INT_EQ(0, result);
    CLOVE_PTR_EQ(item_04->nodes.next, node_03);
    CLOVE_PTR_EQ(item_04->nodes.prev, node_02);
    CLOVE_PTR_EQ(node_02->next, (dlist_node_t *)&item_04->nodes);
    CLOVE_PTR_EQ(node_03->prev, (dlist_node_t *)&item_04->nodes);

    dlist_item_clear(item_01);
    dlist_item_clear(item_02);
    dlist_item_clear(item_03);
    dlist_item_clear(item_04);
}

CLOVE_TEST(doublelinkedlists_insert_NULL_after_node)
{
    int value_01 = 13;
    int value_02 = 23;
    dlist_item_t *item_01=NULL;
    dlist_item_t *item_02=NULL;
    
    // initialize new items
    int result = dlist_item_new(&value_01, (dlist_item_t **)&item_01);
    result = dlist_item_new(&value_02, (dlist_item_t **)&item_02);
    
    dlist_node_t *root_node = NULL;
    dlist_node_t *node_01 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_01->nodes );
    dlist_node_t *node_02 = dlist_append((dlist_node_t **)&root_node, (dlist_node_t *)&item_02->nodes );

    // insert NULL after node_02
    result = dlist_insert_after(NULL, (dlist_node_t *)&item_02->nodes);
    
    CLOVE_INT_EQ(-1, result);
    
    dlist_item_clear(item_01);
    dlist_item_clear(item_02);
}

CLOVE_TEST(doublelinkedlists_insert_node_after_NULL)
{
    int value_01 = 13;
    dlist_item_t *item_01=NULL;

    // initialize new items
    int result = dlist_item_new(&value_01, (dlist_item_t **)&item_01);

    // insert node_01 after NULL
    result = dlist_insert_after((dlist_node_t *)&item_01->nodes, NULL);
    
    CLOVE_INT_EQ(-1, result);

    dlist_item_clear(item_01);
}