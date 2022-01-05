#pragma once
// #ifndef DYNARRAY_HEADER
// #define DYNARRAY_HEADER

#include <stdint.h>

typedef struct dynarray
{
    size_t size_of_elements;    // typedef of element
    size_t number_of_elements;  // active numbers in array
    size_t capacity;            // total space allocated
    uint8_t *data;              // data
    uint8_t *temp_data;         // copy of data
} dynarray_t;

int dynarray_init(dynarray_t *array, const size_t size_of_element);
#define dynarray_init_type(array, type) dynarray_init(array, sizeof(type));

void dynarray_clear(dynarray_t *array);
size_t dynarray_len(const dynarray_t *array);
size_t dynarray_capacity(const dynarray_t *array);
int dynarray_get(const dynarray_t *array, const size_t index, void *value);
int dynarray_append(dynarray_t *array, const void *value);
int dynarray_remove(dynarray_t *array, const size_t index);

int dynarray_run();

// #endif   // DYNARRAY_HEADER