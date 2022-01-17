# Christmas AIV's exercises

## define C DataStructures
- [x] DynamicArray
- [x] LinkedList
- [ ] DoubleLinkedList
- [ ] Set
- [ ] Dictionary

### DynamicArray
Dynarray was modified the lesson's code with less realloc syscall.
Use the clove.h for tests, updated the project structure, insert bat configurations
and implements the remove symbol.

### LinkedList
Implemented symbols:
 - print_linked_list_elements;
 - reverse;
 - remove_value;
 - remove_by_index.
The preprocessor directive is used to do some casts, it is imported the clove.h
 for tests, it is inserted bat configurations.

#### Known errors (but ignored causes):
There are a probably logic errors into symbols:
- reverse
- remove_value
- remove_by_index
because in these case the returned linked_list doesn't correspond to what was expected.

In particular:
- reverse symbol losts 1st element of the original linked list;
- remove_first_value breaks the linked list (test is commented);
- remove_by_index fails to remove an element with index into list elements
 limits (test failed)