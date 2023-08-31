#include <stdio.h>
#include <stdlib.h>
#include "set.h"

int main()
{
    Set* s = createSet();

    for (int i = 0; i < 5; i++)
    {
        int* element = (int*) malloc(sizeof(int));
        *element = i;
        add(s, element);
    }

    int sz = size(s);
    for (int i = 0; i < sz; i++)
    {
        int* element = (int*) pop(s);
        printf("%d ", *element);
        free(element);
    }

    freeSet(s);
    return 0;
}