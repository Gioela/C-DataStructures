#include "clove.h"
#include "test_linkedlists.h"

CLOVE_RUNNER(linked_list_new_string_item_t, linked_list_get_tail,
             linked_list_append_1_string_item_t,
             linked_list_append_1_string_item_t_err,
             linked_list_append_3_string_item_t,
             linked_list_reverse,
             linked_list_remove_first_value,
             linked_list_remove_middle_value,
             linked_list_remove_tail_value,
             linked_list_remove_by_index_zero,
             linked_list_remove_by_negative_index,
             linked_list_remove_by_index,
             linked_list_pop_element,
             );