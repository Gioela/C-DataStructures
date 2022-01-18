#pragma once
#include "clove.h"
#include "dynarray.h"

CLOVE_TEST(dynamic_array_init)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    CLOVE_INT_EQ(sizeof(int), array.size_of_elements);      // typedef of element
    CLOVE_INT_EQ(0, array.number_of_elements);              // active numbers in array - length
    CLOVE_INT_EQ(0, array.capacity);                        // total space allocated - capacity
    CLOVE_NULL(array.data);                                 // data
    // CLOVE_INT_EQ(sizeof(int), array.temp_data)              // free of the data's copy space
    
    dynarray_clear(&array);
}

CLOVE_TEST(dynamic_array_clear)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    int a = 100;
    int b = 200;
    int c = 300;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_append(&array, &c);

    dynarray_clear(&array);

    CLOVE_INT_EQ(sizeof(int), array.size_of_elements);      // typedef of element
    CLOVE_INT_EQ(0, array.number_of_elements);              // active numbers in array - length
    CLOVE_INT_EQ(0, array.capacity);                        // total space allocated - capacity
    CLOVE_NULL(array.data);                                 // data
    CLOVE_NULL(array.temp_data);                            // free of the data's copy space
}

CLOVE_TEST(dynamic_array_append_1_element)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    int a = 100;
    dynarray_append(&array, &a);
    
    CLOVE_INT_EQ(1, array.number_of_elements);      // active numbers in array
    CLOVE_INT_EQ(4, array.capacity);                // check increase capacity's value
    
    dynarray_clear(&array);
}

CLOVE_TEST(dynamic_array_append_5_element)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    int a = 100;
    int b = 200;
    int c = 300;
    int d = 400;
    int e = 500;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_append(&array, &c);
    dynarray_append(&array, &d);
    dynarray_append(&array, &e);
    
    CLOVE_INT_EQ(5, array.number_of_elements);      // active numbers in array
    CLOVE_INT_EQ(8, array.capacity);                // check increase capacity's value
    
    dynarray_clear(&array);
}

CLOVE_TEST(dynamic_array_get_element_by_index_1st_element)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    int a = 100;
    int b = 200;
    int c = 300;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_append(&array, &c);
    
    int d;
    int result_get = dynarray_get_element_by_index(&array, 0, &d);
    CLOVE_INT_EQ(0, result_get);                    // check the returned value from function
    CLOVE_INT_EQ(100, d);                           // check if the ref d is the same of the 0 (zero) index element

    dynarray_clear(&array);
}

CLOVE_TEST(dynamic_array_get_element_by_index_middle_element)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    int a = 100;
    int b = 200;
    int c = 300;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_append(&array, &c);
    
    int d;
    int result_get = dynarray_get_element_by_index(&array, 1, &d);
    CLOVE_INT_EQ(0, result_get);                    // check the returned value from function
    CLOVE_INT_EQ(200, d);                           // check if the ref d is the same of the 1nd index element

    dynarray_clear(&array);
}

CLOVE_TEST(dynamic_array_get_element_by_index_tail_element)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    int a = 100;
    int b = 200;
    int c = 300;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_append(&array, &c);
    
    int d;
    int result_get = dynarray_get_element_by_index(&array, 2, &d);
    CLOVE_INT_EQ(0, result_get);                   // check the returned value from remove function
    CLOVE_INT_EQ(300, d);                          // check if the ref d is the same of the 2nd index element

    dynarray_clear(&array);
}

CLOVE_TEST(dynamic_array_get_element_by_index_out_of_bounds)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    int a = 100;
    int b = 200;
    int c = 300;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_append(&array, &c);
    
    int d = 0;
    int result_get = dynarray_get_element_by_index(&array, 5, &d);
    CLOVE_INT_EQ(-1, result_get);                   // check the returned value from remove function
    CLOVE_INT_EQ(d, 0);                             // check if the ref d is changed

    dynarray_clear(&array);
}

CLOVE_TEST(dynamic_array_get_length_no_elements)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    CLOVE_INT_EQ(0, array.number_of_elements);      // check the array.number_of_elements property
    CLOVE_INT_EQ(0, dynarray_len(&array));          // check dynarray_len symbol
    // free(&source);
    dynarray_clear(&array);
}

CLOVE_TEST(dynamic_array_get_length)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    int a = 100;
    int b = 200;
    int c = 300;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_append(&array, &c);
    
    CLOVE_INT_EQ(3, array.number_of_elements);      // check the array.number_of_elements property
    CLOVE_INT_EQ(3, dynarray_len(&array));          // check dynarray_len symbol
    // free(&source);
    dynarray_clear(&array);
}

CLOVE_TEST(dynamic_array_get_capacity_no_elements)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    CLOVE_INT_EQ(0, array.capacity);                // check array.capacity's property
    CLOVE_INT_EQ(0, dynarray_capacity(&array));     // check array.capacity's symbol

    dynarray_clear(&array);
}

CLOVE_TEST(dynamic_array_get_capacity_standard)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    int a = 100;
    int b = 200;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    
    CLOVE_INT_EQ(4, array.capacity);                // check array.capacity's property
    CLOVE_INT_EQ(4, dynarray_capacity(&array));     // check array.capacity's symbol
    
    dynarray_clear(&array);
}

CLOVE_TEST(dynamic_array_get_capacity_increased)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    int a = 100;
    int b = 200;
    int c = 300;
    int d = 400;
    int e = 500;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_append(&array, &c);
    dynarray_append(&array, &d);
    dynarray_append(&array, &e);

    CLOVE_INT_EQ(8, array.capacity);                // check array.capacity's property
    CLOVE_INT_EQ(8, dynarray_capacity(&array));     // check array.capacity's symbol
    
    dynarray_clear(&array);
}


CLOVE_TEST(dynamic_array_remove_1st_element)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    int a = 100;
    int b = 200;
    int c = 300;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_append(&array, &c);

    int result_remove = dynarray_remove(&array, 0);

    CLOVE_INT_EQ(0, result_remove);                 // check the result int value
    CLOVE_INT_EQ(2, array.number_of_elements);      // check the array.number_of_elements

    dynarray_clear(&array);
}

CLOVE_TEST(dynamic_array_remove_element)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    int a = 100;
    int b = 200;
    int c = 300;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_append(&array, &c);

    int result_remove = dynarray_remove(&array, 2);

    CLOVE_INT_EQ(0, result_remove);                 // check the result int value
    CLOVE_INT_EQ(2, array.number_of_elements);      // check the array.number_of_elements

    dynarray_clear(&array);
}

CLOVE_TEST(dynamic_array_remove_element_out_of_bounds)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    int a = 100;
    int b = 200;
    int c = 300;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_append(&array, &c);

    int result_remove = dynarray_remove(&array, 5);

    CLOVE_INT_EQ(-1, result_remove);                // check the result int value
    CLOVE_INT_EQ(3, array.number_of_elements);      // check the array.number_of_elements
   
    dynarray_clear(&array);
}

CLOVE_TEST(dynamic_array_remove_element_with_negative_index)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
    int a = 100;
    int b = 200;
    int c = 300;
    dynarray_append(&array, &a);
    dynarray_append(&array, &b);
    dynarray_append(&array, &c);

    int result_remove = dynarray_remove(&array, -5);

    CLOVE_INT_EQ(-1, result_remove);                // check the result int value
    CLOVE_INT_EQ(3, array.number_of_elements);      // check the array.number_of_elements
    
    dynarray_clear(&array);
}

CLOVE_TEST(dynarray_remove_element_decrease_capacity)
// CLOVE_TEST(dynamic_array_remove_element_with_decrease_capacity)
{
    dynarray_t array;
    dynarray_init_type(&array, int );
    
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

    CLOVE_INT_EQ(9, array.number_of_elements);      // check the property array.number_of_elements
    CLOVE_INT_EQ(12, array.capacity);               // check the property array.capacity

    int result_remove = dynarray_remove(&array, 2);
    CLOVE_INT_EQ(0, result_remove);                 // check the result int value
    
    result_remove = dynarray_remove(&array, 2);
    CLOVE_INT_EQ(0, result_remove);                 // check the result int value
    
    result_remove = dynarray_remove(&array, 2);
    CLOVE_INT_EQ(0, result_remove);                 // check the result int value
    
    result_remove = dynarray_remove(&array, 2);
    CLOVE_INT_EQ(0, result_remove);                 // check the result int value
    
    CLOVE_INT_EQ(5, array.number_of_elements);      // check the property array.number_of_elements
    CLOVE_INT_EQ(8, array.capacity);                // check the property array.capacity

    dynarray_clear(&array);
}
