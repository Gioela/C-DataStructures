#define CLOVE_SUITE_NAME dictionary_test
#include "clove-experimental.h"
#include "dictionary.h"

CLOVE_TEST(InsertOneElement)
{
    dictionary_table_t *dictionary = set_dictionary_new(4);

    set_node_t *node = dictionary_insert_node(dictionary, "pippo", 5, "ciao");

    CLOVE_NOT_NULL(node);
    CLOVE_STRING_EQ("pippo", node->key);
    CLOVE_STRING_EQ("ciao", node->value);
    CLOVE_UINT_EQ(1, dictionary->elements_inserted);
}

CLOVE_TEST(IncreaseHashMapSize)
{
    dictionary_table_t *dictionary = set_dictionary_new(2);

    set_node_t *node_01 = dictionary_insert_node(dictionary, "pippo", 5, "ciao pippo");
    set_node_t *node_02 = dictionary_insert_node(dictionary, "pluto", 5, "ciao pluto");
    set_node_t *node_03 = dictionary_insert_node(dictionary, "topolino", 5, "ciao topolino");

    CLOVE_UINT_EQ(3, dictionary->elements_inserted);
    CLOVE_UINT_EQ(4, dictionary->hashmap_size);
}