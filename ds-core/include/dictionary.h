#pragma once
#include <stdlib.h>

typedef struct set_node
{
    const char *key;
    const char *value;
    size_t key_len;
    struct set_node *next;

} set_node_t;

typedef struct dictionary_table
{
    set_node_t **nodes;
    size_t hashmap_size;
    unsigned int elements_inserted;
} dictionary_table_t;

dictionary_table_t *set_dictionary_new(const size_t hashmap_size);
set_node_t *dictionary_insert_node(dictionary_table_t *table, const char *key, const size_t key_len, const char *value);
size_t djb33x_hash(const char *key, const size_t keylen);
dictionary_table_t *set_table_search(dictionary_table_t *table, const char *key, const size_t key_len);
dictionary_table_t *set_table_remove(dictionary_table_t *table, const char *key, const size_t key_len);
int set_table_clear(dictionary_table_t *table);

int increase_hashmapsize(dictionary_table_t **table);