#pragma once
#include "clove.h"
#include "dynarray.h"

CLOVE_TEST(dynamic_array_init)
{
    unsigned long long source[5] = { 0, 0, 0, 0, 0 };
    dynarray_init_type(&source, int );

    CLOVE_INT_EQ(sizeof(int), source[0]);   // typedef of element
    CLOVE_INT_EQ(0, source[1]);             // active numbers in array - length
    CLOVE_INT_EQ(0, source[2]);             // total space allocated - capacity
    CLOVE_NULL(source[3]);                  // data
    // CLOVE_INT_EQ(sizeof(int), source[4]);   // copy of data
    free(&source);
}

CLOVE_TEST(dynamic_array_clear)
{
    unsigned long long source[5] = { 0, 0, 0, 0, 0 };
    dynarray_init_type(&source, int );
    dynarray_clear(&source);

    CLOVE_INT_EQ(sizeof(int), source[0]);   // typedef of element
    CLOVE_INT_EQ(0, source[1]);             // active numbers in array - length
    CLOVE_INT_EQ(0, source[2]);             // total space allocated - capacity
    CLOVE_NULL(source[3]);                  // data
    CLOVE_NULL(source[4]);                  // free of the data's copy space
}

CLOVE_TEST(dynamic_array_append_5_element)
{
    unsigned long long source[5] = { 0, 0, 0, 0, 0 };
    dynarray_init_type(&source, int );
    
    int num_elem = 5;
    for (int i = 0; i < num_elem; ++i)
    {
        int a = i * 100;
        dynarray_append(&source, &a);
    }
    
    CLOVE_INT_EQ(num_elem, source[1]);              // active numbers in array
    CLOVE_INT_EQ(num_elem/4 * 4 + 4, source[2]);    // check increase capacity's value
    
    free(&source);
}

CLOVE_TEST(dynamic_array_get_element)
{
    unsigned long long source[5] = { 0, 0, 0, 0, 0 };
    dynarray_init_type(&source, int );
    
    int a = 2;
    int b = 3;
    dynarray_append(&source, &a);
    dynarray_append(&source, &b);

    int c;
    dynarray_get(&source, 0, &c);
    CLOVE_INT_EQ(2, c);             // value in first position of data

    free(&source);
}

CLOVE_TEST(dynamic_array_get_length)
{
    unsigned long long source[5] = { 0, 0, 0, 0, 0 };
    dynarray_init_type(&source, int );

    int num_elem = 5;
    for (int i = 0; i < num_elem; ++i)
    {
        int a = i * 100;
        dynarray_append(&source, &a);
    }

    CLOVE_INT_EQ(num_elem, source[1]);         // active numbers in array
    free(&source);
}

CLOVE_TEST(dynamic_array_get_capacity)
{
    unsigned long long source[5] = { 0, 0, 0, 0, 0 };
    dynarray_init_type(&source, int );

    int num_elem = 15;
    for (int i = 0; i < num_elem; ++i)
    {
        int a = i * 100;
        dynarray_append(&source, &a);
    }

    CLOVE_INT_EQ(num_elem/4 * 4 + 4, source[2]);    // check increase capacity's value
    free(&source);
}

CLOVE_TEST(dynamic_array_remove_one_element)
{
    unsigned long long source[5] = { 0, 0, 0, 0, 0 };
    dynarray_init_type(&source, int );

    int num_elem = 3;
    for (int i = 0; i < num_elem; ++i)
    {
        int a = i * 100;
        dynarray_append(&source, &a);
    }

    dynarray_remove(&source, 0);

    CLOVE_INT_EQ(num_elem - 1, source[1]);          // active numbers in array: num_elem - 1
    free(&source);
}

CLOVE_TEST(dynamic_array_remove_elements_get_capacity)
{
    unsigned long long source[5] = { 0, 0, 0, 0, 0 };
    dynarray_init_type(&source, int );

    int num_elem = 17;
    for (int i = 0; i < num_elem; ++i)
    {
        int a = i * 100;
        dynarray_append(&source, &a);
    }

    dynarray_remove(&source, 2);
    dynarray_remove(&source, 5);
    dynarray_remove(&source, 8);

    CLOVE_INT_EQ(source[1]/4 * 4 + 4, source[2]);    // check decrease capacity's value
    free(&source);
}