#include <stdio.h>
#include "memorycounter.h"

int memory_allocator_counter = 0;

void *mac_malloc(size_t size)
{
    memory_allocator_counter++;
    return malloc(size);
}

void mac_free(void *ptr)
{
    memory_allocator_counter--;
    free(ptr);
}