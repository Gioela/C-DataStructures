# Christmas AIV's exercises

## Define C DataStructures
- [x] DynamicArray
- [x] LinkedList
- [x] DoubleLinkedList*
- [x] Set*
- [ ] Dictionary


*not yet the extra features

### DynamicArray
Dynarray was modified the lesson's code with less realloc syscall.
Use the clove.h for 18 tests, updated the project structure, insert bat configurations
and implements the remove symbol.

### LinkedList
Implemented symbols:
 - print_linked_list_elements;
 - reverse;
 - remove_value;
 - remove_by_index.
The preprocessor directive is used to do some casts, it is imported the clove.h
 for tests, it is inserted bat configurations.

##### Known errors (but ignored causes):
There are a probably logic errors into LinkedList symbols:
- reverse
- remove_value
- remove_by_index
because in these case the returned linked_list doesn't correspond to what was expected.

In particular:
- reverse symbol losts 1st element of the original linked list;
- remove_first_value breaks the linked list (test is commented);
- remove_by_index fails to remove an element with index into list elements
 limits (test failed)

### DoubleLinkedList
Implemented and tested symbols:
 [x] (private) initialize dlinked_list node;
 [x] append nodes;
 [x] create new item;
 [x] get tail of dlinked_list;
 [x] print dlinked_list values;
 [x] dlist get value;
 [x] clear item;
 [x] remove_value;
 [x] search_by_value;
 [x] Implement insert node after another one;
 [x] Implement insert node before another one;
 [] [extra features] implement shuffling;
 [] [extra features] remove_by_index.
The preprocessor directive is used to do some casts, it is imported the clove.h
 for tests, it is inserted bat configurations.

 ### Sets
 Implemented and tested symbols:
 [x] unique keys (fix myset_insert function);
 [x] search;
 [x] removal;
 [ ] [extra features] refactor myset code with the linkedlists implementation

 ### Dictionary