#include "mysets.h"

#define mock_hash _myset_get_table_index

myset_table_t *myset_table_new(const size_t hashmap_size)
{
    myset_table_t *table = malloc(sizeof(myset_table_t));

    if (!table)
    {
        return NULL;
    }

    table->hashmap_size = hashmap_size;
    table->nodes = calloc(table->hashmap_size, sizeof(myset_node_t *));

    if (!table->nodes)
    {
        free(table);
        return NULL;
    }
    return table;
}

size_t djb33x_hash(const char *key, const size_t key_len)
{
    size_t hash = 5381;

    for (size_t i = 0; i < key_len; i++)
    {
        hash = ((hash << 5) + hash) ^ key[i];
    }
    return hash;
}

// myset_node_t *_myset_get_table_index(myset_table_t *table, const char *key, const size_t keylen)
// {
//     size_t hash = djb33x_hash(key, keylen);
//     size_t index = hash % table->hashmap_size;
//     myset_node_t *head = table->nodes[index];
//     return head;
// }

size_t _myset_get_hash_index(myset_table_t *table, size_t(*hash_function)(const char *key, const size_t key_len))
{
    return (size_t) hash_function % table->hashmap_size;
}

// myset_node_t *myset_insert(myset_table_t *table, const char *key, const size_t key_len, size_t(*hash_index_function)(const char *key, const size_t key_len))
myset_node_t *myset_insert(myset_table_t *table, const char *key, const size_t key_len)
{
    // size_t hash = djb33x_hash(key, key_len);
    // size_t hash = hash_function;
    // size_t index = hash % table->hashmap_size;
    size_t index = _myset_get_hash_index(table, djb33x_hash(key, key_len) );
    myset_node_t *head = table->nodes[index];

    if (!head)
    {
        table->nodes[index] = malloc(sizeof(myset_node_t));
        if (!table->nodes[index])
        {
            return NULL;
        }
        table->nodes[index]->key = key;
        table->nodes[index]->key_len = key_len;
        table->nodes[index]->next = NULL;

        return table->nodes[index];
    }

    myset_node_t *tail = head;
    while (head)
    {
        if (head->key_len == key_len && strcmp(key, head->key) == 0)
        {
            return NULL;
        }
        tail = head;
        head = head->next;
    }

    myset_node_t *new_item = malloc(sizeof(myset_node_t));

    if (!new_item)
    {
        return NULL;
    }

    new_item->key = key;
    new_item->key_len = key_len;
    new_item->next = NULL;

    tail->next = new_item;
    new_item->prev = tail;
    return tail;
}

myset_node_t *myset_table_search_value(myset_table_t *table, const char *key, const size_t key_len)
{
    size_t index = _myset_get_hash_index(table, djb33x_hash(key, key_len) );
    myset_node_t *head = table->nodes[index];
    // myset_node_t *head = _myset_get_table_index(table, key, keylen);

    if (!head)
    {
        return NULL;
    }

    myset_node_t *tail = head;
    while (head)
    {
        if (head->key_len == key_len && strcmp(key, head->key) == 0)
        {
            return head;
        }
        tail = head;
        head = head->next;
    }

    return NULL;
}

myset_node_t *myset_table_remove_value(myset_table_t *table, const char *key, const size_t key_len)
{
    size_t index = _myset_get_hash_index(table, djb33x_hash(key, key_len) );
    myset_node_t *head = table->nodes[index];
    // myset_node_t *head = _myset_get_table_index(table, key, key_len);

    if (!head)
    {
        return NULL;
    }

    myset_node_t *tail = head;
    while (head)
    {
        if (head->next)
        {
            if (head->key_len == key_len && strcmp(key, head->key) == 0)
            {
                if (!head->prev)
                {
                    head->next->prev = NULL;
                    head->next = NULL;
                }
                else if (!head->next)
                {
                    head->prev->next = NULL;
                    head->prev = NULL;
                }
                else
                {
                    head->prev->next = head->next;
                    head->next->prev = head->prev;
                    head->next = NULL;
                    head->prev = NULL;
                }

                head->prev->next = head->next;
                head->next->prev = head->prev;
                head->next = NULL;
                head->prev = NULL;

                return head;
            }
        }
        else
        {
            return head;
        }
        tail = head;
        head = head->next;
    }

    return NULL;
}

int myset_table_length(myset_table_t *table)
{
    if (!table)
    {
        return -1;
    }

    int lenght = 0;

    puts("length test");
    myset_node_t *node = (*table->nodes);
    while (node)
    {
        ++lenght;
        printf("cycle: %d\n", lenght);
        // (*table->nodes) = (*table->nodes)->next;
        node = node->next;
    }

    return lenght;
}

int myset_table_clear(myset_table_t *table)
{
    if (!table)
    {
        return -1;
    }

    free(table->nodes);

    table->hashmap_size = 0;
    free(table);

    return 0;
}