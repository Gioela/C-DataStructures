#define CLOVE_SUITE_NAME MysetTest
#include "clove-experimental.h"
#include "mysets.h"

#define mock_hash 0

int _get_hash_index()
{
    return 0;
}

myset_table_t *table = NULL;

CLOVE_SUITE_SETUP()
{
    // puts("SETUP");
    table = myset_table_new(3);
}

CLOVE_SUITE_TEARDOWN()
{
    // puts("TEARDOWN");
    // myset_table_clear(table);
}

CLOVE_TEST(myset_clear_table_structure)
{
    CLOVE_INT_EQ(0, myset_table_clear(table));
}

CLOVE_TEST(myset_clear_table_structure_with_one_node)
{
    myset_node_t *node = myset_insert(table, "ciao", 4);

    CLOVE_INT_EQ(0, myset_table_clear(table));
}

CLOVE_TEST(myset_clear_table_structure_with_two_nodes)
{
    myset_node_t *node_01 = myset_insert(table, "ciao", 4);
    myset_node_t *node_02 = myset_insert(table, "ciaone", 6);

    CLOVE_INT_EQ(0, myset_table_clear(table));
}

CLOVE_TEST(myset_clear_table_structure_NULL)
{
    table = NULL;

    CLOVE_INT_EQ(-1, myset_table_clear(table));
}

CLOVE_TEST(myset_get_table_length)
{
    // myset_node_t *node_01 = myset_insert(table, "ciao", 4);
    // myset_node_t *node_02 = myset_insert(table, "ciaone", 6);
    // myset_node_t *node_03 = myset_insert(table, "third", 5);

    // CLOVE_INT_EQ(3, myset_table_length(table));
}

CLOVE_TEST(myset_get_table_length_NULL)
{
    table = NULL;
    CLOVE_INT_EQ(-1, myset_table_length(table));
}

CLOVE_TEST(mysets_insert_one_element)
{
    // myset_node_t *node_01 = myset_insert(table, "ciao", 4, _get_hash_index());
    myset_node_t *node_01 = myset_insert(table, "ciao", 4);

    CLOVE_NOT_NULL(node_01);
}

CLOVE_TEST(mysets_insert_same_element)
{
    // myset_node_t *node_01 = myset_insert(table, "ciao", 4, _get_hash_index());
    // myset_node_t *node_02 = myset_insert(table, "ciao", 4, _get_hash_index());

    myset_node_t *node_01 = myset_insert(table, "ciao", 4);
    myset_node_t *node_02 = myset_insert(table, "ciao", 4);

    CLOVE_NOT_NULL(node_01);
    CLOVE_NULL(node_02);
}

CLOVE_TEST(mysets_insert_tree_element)
{
    myset_node_t *node_01 = myset_insert(table, "ciao", 4);
    myset_node_t *node_02 = myset_insert(table, "ciaone", 6);
    myset_node_t *node_03 = myset_insert(table, "third", 5);

    CLOVE_NOT_NULL(node_01);
    CLOVE_NOT_NULL(node_02);
    CLOVE_NOT_NULL(node_03);
}

CLOVE_TEST(mysets_search_value)
{
    myset_node_t *node_01 = myset_insert(table, "ciao", 4);
    myset_node_t *node_02 = myset_insert(table, "ciaone", 6);
    myset_node_t *node_03 = myset_insert(table, "third", 5);

    CLOVE_PTR_EQ(node_01, myset_table_search_value(table, "ciao", 4));
}

CLOVE_TEST(mysets_search_value_not_present)
{
    myset_node_t *node_01 = myset_insert(table, "ciao", 4);
    myset_node_t *node_02 = myset_insert(table, "ciaone", 6);
    myset_node_t *node_03 = myset_insert(table, "third", 5);

    CLOVE_NULL(myset_table_search_value(table, "ciaobello", 9));
}

CLOVE_TEST(mysets_remove_property_item)
{
    myset_node_t *node_01 = myset_insert(table, "ciao", 4);
    myset_node_t *node_01b = myset_insert(table, "ciao", 4);
    myset_node_t *node_02 = myset_insert(table, "ciaone", 6);
    myset_node_t *node_03 = myset_insert(table, "third", 5);

    myset_node_t *removed = myset_table_remove_value(table, "ciao", 4);

    CLOVE_NULL(removed->prev);
    CLOVE_NULL(removed->next);
}

CLOVE_TEST(mysets_remove_first_value)
{
    myset_node_t *node_01 = myset_insert(table, "ciao", 4);
    myset_node_t *node_02 = myset_insert(table, "ciaone", 6);
    myset_node_t *node_03 = myset_insert(table, "third", 5);

    myset_node_t *removed = myset_table_remove_value(table, "ciao", 4);

    CLOVE_PTR_EQ(node_01, removed);
    CLOVE_PTR_EQ(table, node_02);
}

// CLOVE_TEST(mysets_remove_middle_value)
// {
//     myset_node_t *node_01 = myset_insert(table, "ciao", 4);
//     myset_node_t *node_02 = myset_insert(table, "ciaone", 6);
//     myset_node_t *node_02b = myset_insert(table, "viaone", 6);
//     myset_node_t *node_02c = myset_insert(table, "ziaone", 6);
//     myset_node_t *node_03 = myset_insert(table, "third", 5);

//     myset_node_t *removed = myset_table_remove_value(table, "ciaone", 6);

//     CLOVE_PTR_EQ(node_02, removed);
//     CLOVE_PTR_EQ(table, node_01);

// }

CLOVE_TEST(mysets_remove_tail_value)
{
    myset_node_t *node_01 = myset_insert(table, "ciao", 4);
    myset_node_t *node_02 = myset_insert(table, "ciaone", 6);
    myset_node_t *node_03 = myset_insert(table, "third", 5);

    myset_node_t *removed = myset_table_remove_value(table, "ciao", 4);

    CLOVE_PTR_EQ(node_03, removed);
    CLOVE_PTR_EQ(table, node_02);
}
