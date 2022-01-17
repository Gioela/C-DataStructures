#include <stdio.h>
#include "dynarray.h"
#include "linkedlists.h"

#define space puts("--------------------")

int main()
{
    if (dynarray_run() != 0)
    {
        puts("[ERROR] - DYANRRAY");
        return -1;
    }

    space;

    if (list_run() != 0)
    {
        puts("[ERROR] - LINKED_LISTS");
        return -1;
    }
    
    puts("END CODE");
    return 0;
}