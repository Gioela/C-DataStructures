#include "clove.h"
#include "test_dynarray.h"

// CLOVE_RUNNER(DynamicArray_Init);

CLOVE_RUNNER(dynamic_array_init, dynamic_array_clear, dynamic_array_append_5_element,
             dynamic_array_get_element, dynamic_array_get_length, dynamic_array_get_capacity,
             dynamic_array_remove_one_element,
             dynamic_array_remove_elements_get_capacity
            );