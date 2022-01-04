// #include <stdlib.h>
// #include <stdint.h>
#include <stdio.h>
#include "dynarray.h"

int main()
{
    if (dynarray_run() != 0)
    {
        puts("[ERROR] - DYANRRAY");
        return -1;
    }
    puts("END CODE");
    return 0;
}