#pragma once

extern int memory_allocator_counter;

#ifdef DEBUG
    #define malloc mac_malloc
    #define free mac_free
#endif

void *mac_malloc(size_t size);
void mac_free(void *ptr);