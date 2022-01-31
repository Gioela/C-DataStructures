#pragma once
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include "linkedlists.h"
#include "doublelinkedlists.h"

typedef struct set_node
{
    const char *key;
    size_t key_len;
    struct set_node *next;
    struct set_node *prev;
} myset_node_t;

/*
 * myset_table structure
 *
 * @param nodes myset_node_t here are various properties (e.g. pointer
 *              to previous and next element)
 * @param hashmap_size
 */
typedef struct set_table
{
    myset_node_t **nodes;
    size_t hashmap_size;
} myset_table_t;

/*
 * Create new object myset_table_t
 *
 * @param hashmap_size Size of the hashmap of the new myset_table_t
 *
 * @return A pointer to new type myset_table_t
 */
myset_table_t *myset_table_new(const size_t hashmap_size);

/*
 * Insert a new myset_node_t into myset_table_t
 *
 * @param table myset_table_t into which node must be inserted
 * @param key Char array which must be inserted
 * @param key_len Length of the key to calculate the key hash
 *
 * @return A pointer to new myset_node_t
 */
myset_node_t *myset_insert(myset_table_t *table, const char *key, const size_t key_len);
myset_node_t *myset_insert_mokked(myset_table_t *table, const char *key, const size_t key_len, size_t (*hash_index_function)(const char *key, const size_t key_len));

/*
 * Calculate the hash index
 *
 * @param table myset_table_t into which want to calculate hash
 * @param hash_function hash function which want to use
 *
 * @return Returned size_t index calculated by hash_function
 */
size_t _myset_get_hash_index(myset_table_t *table, size_t (*hash_function)(const char *key, const size_t key_len));

/*
 * Calculate the hash of the key with keylen size
 *
 * @param key Char array which needs the hash
 * @param keylen Length of the key
 *
 * @return Return the hash of the key which generated with keylen value
 */
size_t djb33x_hash(const char *key, const size_t key_len);

/*
 * Get the myset_table number of elements
 *
 * @param table myset_table wich want to know the length
 *
 * @return Return the number of nodes in the table. In case of error, return -1
 */
int myset_table_length(myset_table_t *table);

/*
 * Clear the myset_table structure
 *
 * @param table myset_table wich want to clean
 *
 * @return Return 0 if success, -1 otherwise
 */
int myset_table_clear(myset_table_t *table);

/*
 * Search value into set
 *
 * @param table myset_table were value must be search
 * @param key key want to search
 * @param key_len length of key
 *
 * @return myset_node_t element if it found, NULL otherwise
 */
myset_node_t *myset_table_search_value(myset_table_t *table, const char *key, const size_t key_len);

/*
 * Remove the value from set
 *
 * @param table myset_table from wich want to remove value
 * @param key key which want to remove
 * @param key_len length of key
 *
 * @return myset_node_t element removed
 */
myset_node_t *myset_table_remove_value(myset_table_t *table, const char *key, const size_t key_len);