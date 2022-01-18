#pragma once
// #ifndef DYNARRAY_HEADER
// #define DYNARRAY_HEADER

#include <stdint.h>

/*
 * Dynamic Array structure
 */
typedef struct dynarray
{
    size_t size_of_elements;    // typedef of element
    size_t number_of_elements;  // active numbers in array
    size_t capacity;            // total space allocated
    uint8_t *data;              // data
    uint8_t *temp_data;         // copy of data
} dynarray_t;

/*
 * Initialize dynamic array.
 * In case of errors will be return -1, 0 otherwise.
 *
 * @param array Array to initialize
 * @param size_of_element Which type of elements will be stored into array
 */
int dynarray_init(dynarray_t *array, const size_t size_of_element);
#define dynarray_init_type(array, type) dynarray_init(array, sizeof(type));

/*
 * Clear the dynamic array properties.
 *
 * @param array Array to clean
 */
void dynarray_clear(dynarray_t *array);

/*
 * Return the length of the given dynamic array.
 * NOTE: Length is given by the number of elements into array
 *
 * @param array Array whose length you want to know
 */
size_t dynarray_len(const dynarray_t *array);

/*
 * Return the capacity of the given dynamic array.
 * NOTE: Capacity is how many memory is occupied by the array
 *
 * @param array Array whose capacity you want to know
 */
size_t dynarray_capacity(const dynarray_t *array);

/*
 * Return the index element into array, if it found, otherwise will return
 * the error code -1.
 *
 * @param array Array from you want take element
 * @param index Index of element into the array
 * @param value Pointer, where the value will be stored
 */
int dynarray_get_element_by_index(const dynarray_t *array, const size_t index, void *value);

/*
 * Append value at the end of the dynamic array.
 * In case of errors will be return -1, 0 otherwise.
 * 
 * @param array Array where element will be append
 * @param value Value to be append into the array
 */
int dynarray_append(dynarray_t *array, const void *value);

/*
 * Remove the value at the given index from the dynamic array.
 * In case of errors will be return -1, 0 otherwise.
 *
 * @param array Array where element will be removed
 * @param index Position of the element which you want to remove
 */
int dynarray_remove(dynarray_t *array, const size_t index);

// #endif   // DYNARRAY_HEADER