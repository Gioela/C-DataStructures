#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "dynarray.h"

/*
 * Initialize dynamic array.
 * In case of errors will be return -1, 0 otherwise.
 *
 * @param array Array to initialize
 * @param size_of_element Which type of elements will be stored into array
 */
int dynarray_init(dynarray_t *array, const size_t size_of_element)
{
    array->size_of_elements = size_of_element;
    array->number_of_elements = 0;
    array->capacity = 0;
    array->data = NULL;
    array->temp_data = malloc(size_of_element);
    if (!array->temp_data) return -1;
    return 0;
}

/*
 * Clear the dynamic array properties.
 *
 * @param array Array to clean
 */
void dynarray_clear(dynarray_t *array)
{
    array->capacity = 0;
    array->number_of_elements = 0;
    free(array->data);
    array->data = NULL;
    free(array->temp_data);
    array->temp_data = NULL;
}

/*
 * Return the length of the given dynamic array.
 * NOTE: Length is given by the number of elements into array
 *
 * @param array Array whose length you want to know
 */
size_t dynarray_len(const dynarray_t *array)
{
    return array->number_of_elements;
}

/*
 * Return the capacity of the given dynamic array.
 * NOTE: Capacity is how many memory is occupied by the array
 *
 * @param array Array whose capacity you want to know
 */

size_t dynarray_capacity(const dynarray_t *array)
{
    return array->capacity;
}

/*
 * Return the index element into array, if it found, otherwise will return
 * the error code -1.
 *
 * @param array Array from you want take element
 * @param index Index of element into the array
 * @param value Pointer, where the value will be stored
 */
int dynarray_get(const dynarray_t *array, const size_t index, void *value)
{
    if (index >= array->number_of_elements || index < 0)
    {
        puts("[ERROR] index out of bound exception");
        return -1;
    }
    // calculate the index offset to copy the value of this n-element 
    // from array->data + offset into value
    // (NOTE: size_of_elements tells how many bytes must be copied into value)
    const size_t offset = index * array->size_of_elements;
    memcpy(value, array->data + offset, array->size_of_elements);
    return 0;
}

/*
 * Append value at the end of the dynamic array.
 * In case of errors will be return -1, 0 otherwise.
 * 
 * @param array Array where element will be append
 * @param value Value to be append into the array
 */
int dynarray_append(dynarray_t *array, const void *value)
{
    if (array->number_of_elements + 1 > array->capacity || array->number_of_elements == 0)
    {
        // printf("[DEBUG] (prev) array->capacity: %llu\n", array->capacity);
        const size_t new_capacity = array->capacity + 4;
        // printf("[DEBUG] (new) array->capacity: %llu\n", new_capacity);

        uint8_t *new_ptr = realloc(array->data, array->size_of_elements * new_capacity );
        if (!new_ptr)
        {
            puts("[ERROR] inable to allocate new memory");
            return -1;
        }
        puts("[INFO] allocated new space successfully");
        array->capacity = new_capacity;
        array->data = new_ptr;
    }
    const size_t offset = array->number_of_elements * array->size_of_elements;
    memcpy(array->data + offset, value, array->size_of_elements);
    array->number_of_elements += 1;
    return 0;
}

/*
 * Remove the value at the given index from the dynamic array.
 * In case of errors will be return -1, 0 otherwise.
 *
 * @param array Array where element will be removed
 * @param index Position of the element which you want to remove
 */
int dynarray_remove(dynarray_t *array, const size_t index)
{
    // check index value: inner or outer bounds
    if (index >= array->number_of_elements || index < 0) return -1;

    // calculate the offset => the position of i-element to remove
    const size_t offset = array->size_of_elements * index;

    // printf("[DEBUG][REMOVE][START]\tindex %llu\tarray->number_of_el %llu\tarray->capacity %llu\n",
    //         index, array->number_of_elements, array->capacity);

    // remove element only if it isn't the last element
    if (index < array->number_of_elements - 1)
    {
        // save a bakcup of data
        memcpy(array->temp_data, array->data, array->size_of_elements);
        memmove(array->data + offset, array->data + offset + array->size_of_elements, 
                ( array->number_of_elements - index ) * array->size_of_elements );
        array->number_of_elements -= 1;
        // printf("[INFO][REMOVE][UPDATED] array->number_of_elements %llu\n", array->number_of_elements);
    }
    
    // update array->capacity if capacity is twice of number_of_elements
    // if ( array->capacity % array->number_of_elements == 0)
    if ( array->capacity - 4 > array->number_of_elements)
    {
        // array->capacity = array->number_of_elements;
        array->capacity = array->number_of_elements / 4 * 4 + 4;
        uint8_t *new_pointer = realloc(array->data, array->capacity * array->size_of_elements);
        if (!new_pointer)
        {
            puts("[ERROR] realloc memory in remove function");
            if (index < array->number_of_elements - 1)
            {
                puts("[DEBUG] RESTORE ORIGINAL DATA");
                memmove(array->data + offset + array->size_of_elements, array->data + offset,
                        (array->number_of_elements - index) * array->size_of_elements);
                memcpy(array->data + offset, array->temp_data, array->size_of_elements);    // restore the original data
            }
            return -1;
        }
        printf("[INFO] updated array->capacity %llu - array->number_of_elements %llu\n",
                array->capacity, array->number_of_elements);
    }
    // printf("[DEBUG][REMOVE][END] removed index %llu\n\n", index);
    return 0;
}

/*
 * Simple demonstration of the dynarray's methods.
 */
int dynarray_run()
{
    dynarray_t array;
    dynarray_init_type(&array, int);
    puts("[INFO] new dynamic array initialized");

    int a = 100;
    int b = 200;
    int c = 300;
    int d = 400;
    int e = 500;
    int f = 600;
    int g = 700;
    int h = 800;
    int i = 900;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_append(&array, &c);
    dynarray_append(&array, &d);
    dynarray_append(&array, &e);
    dynarray_append(&array, &f);
    dynarray_append(&array, &g);
    dynarray_append(&array, &h);
    dynarray_append(&array, &i);
    puts("[INFO] dynamic array populated");

    printf("number of elements = %llu\n", dynarray_len(&array));
    printf("capacity = %llu\n", dynarray_capacity(&array));
    for (size_t i = 0; i < dynarray_len(&array); ++i)
    {
        int value;
        if (!dynarray_get(&array, i, &value))
        {
            printf("[%llu] %d\n", i, value);
        }
    }

    printf(">> >> >> REMOVE ELEMENTS << << <<\n");
    dynarray_remove(&array, 8);
    dynarray_remove(&array, 7);
    dynarray_remove(&array, 6);
    dynarray_remove(&array, 2);
    dynarray_remove(&array, 3);
    
    printf("number of elements = %llu\n", dynarray_len(&array));
    printf("capacity = %llu\n", dynarray_capacity(&array));
    for (size_t i = 0; i < dynarray_len(&array); ++i)
    {
        int value;
        if (!dynarray_get(&array, i, &value))
        {
            printf("[%llu] %d\n", i, value);
        }
    }
    
    dynarray_clear(&array);
    return 0;
}