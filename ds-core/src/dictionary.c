#include <string.h>
#include "dictionary.h"

size_t djb33x_hash(const char *key, const size_t key_len)
{
    size_t hash = 5381;

    for (size_t i = 0; i < key_len; i++)
    {
        hash = ((hash << 5) + hash) ^ key[i];
    }
    return hash;
}

dictionary_table_t *set_dictionary_new(const size_t hashmap_size)
{
    dictionary_table_t *table = malloc(sizeof(dictionary_table_t));

    if (!table)
    {
        return NULL;
    }

    table->hashmap_size = hashmap_size;
    table->nodes = calloc(table->hashmap_size, sizeof(set_node_t *));
    table->elements_inserted = 0;

    if (!table->nodes)
    {
        free(table);
        return NULL;
    }
    return table;
}

set_node_t *dictionary_insert_node(dictionary_table_t *table, const char *key, const size_t key_len, const char *value)
{
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;
    set_node_t *head = table->nodes[index];

    if (!head)
    {
        table->nodes[index] = malloc(sizeof(set_node_t));
        if (!table->nodes[index])
        {
            return NULL;
        }

        table->nodes[index]->key = key;
        table->nodes[index]->key_len = key_len;
        table->nodes[index]->value = value;
        table->elements_inserted++;

        return table->nodes[index];
    }

    // verifico univocità della chiave da inserire
    set_node_t *tail = head;
    while (head)
    {
        if (head->key_len == key_len && strcmp(key, head->key) == 0)
        {
            return NULL;
        }
        tail = head;
        head = head->next;
    }

    // alloco spazio per la nuova chiave
    set_node_t *new_item = malloc(sizeof(set_node_t));
    if (!new_item)
    {
        return NULL;
    }

    // inserisco la nuova chiave sull'hashmap già presente
    new_item->key = key;
    new_item->key_len = key_len;
    new_item->next = NULL;
    new_item->value = value,

    tail->next = new_item;

    // CREAZIONE DEL NUOVO DIZIONARIO PER IL NUOVO HASHMAP
    dictionary_table_t *largest_table = set_dictionary_new(table->hashmap_size + 10);

    // sposta il vecchio table sul nuovo
    for (size_t i = 0; i < table->hashmap_size; i++)
    {
        set_node_t *current_node = table->nodes[i];

        while (current_node)
        {
            dictionary_insert_node(largest_table,
                                   current_node->key,
                                   current_node->key_len,
                                   current_node->value);
                                   
            // TODO ANNULLARE IL NEXT 
            if (current_node->next)
            {
                table->nodes[i]->next = NULL;
                puts("PROBLEMI DI IDENTITA...");
                current_node = current_node->next;
            }
        }
    }

    table = largest_table;
    free(largest_table);
}
