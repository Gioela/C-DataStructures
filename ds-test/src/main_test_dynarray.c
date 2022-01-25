#include "clove.h"
#include "test_dynarray.h"

CLOVE_RUNNER(
             dynamic_array_init, 
             dynamic_array_clear,
             dynamic_array_append_1_element, 
             dynamic_array_append_5_element,
             dynamic_array_get_element_by_index_1st_element, 
             dynamic_array_get_element_by_index_middle_element,
             dynamic_array_get_element_by_index_tail_element,
             dynamic_array_get_element_by_index_out_of_bounds,
             dynamic_array_get_length_no_elements,
             dynamic_array_get_length,
             dynamic_array_get_capacity_no_elements,
             dynamic_array_get_capacity_standard,
             dynamic_array_get_capacity_increased,
             dynamic_array_remove_1st_element,
             dynamic_array_remove_element,
             dynamic_array_remove_element_out_of_bounds,
             dynamic_array_remove_element_with_negative_index,
            dynarray_remove_element_decrease_capacity,
            );