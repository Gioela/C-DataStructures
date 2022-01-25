#include "clove.h"
#include "test_doublelinkedlists.h"

CLOVE_RUNNER(
    doublelinkedlists_node_initializer,
    doublelinkedlists_new_item,
    doublelinkedlists_get_item_value,
    doublelinkedlists_append_three_nodes,
    doublelinkedlists_free_item_memory,
    doublelinkedlists_get_tail_node,
    doublelinkedlists_remove_by_value,
    doublelinkedlists_remove_last_value,
    doublelinkedlists_remove_first_value,
    doublelinkedlists_insert_before,
    doublelinkedlists_insert_NULL_before_node,
    doublelinkedlists_insert_node_before_NULL,
    doublelinkedlists_insert_after,
    doublelinkedlists_insert_NULL_after_node,
    doublelinkedlists_insert_node_after_NULL,
)
