#include<stdio.h>
#include "set.h"
int main()
{
    Set* s = createSet();

    for(int i = 0; i < 5; i++)
    {
        // Allocate Memory for Each Element
        int* element = (int*) malloc(sizeof(int));
        *element = i;
        add(s, element, sizeof(int));
    }
    for(int i = 0; i < 5; i++)
    {
        // Allocate Memory for Each Element
        int* element = (int*) malloc(sizeof(int));
        *element = i;
        add(s, element, sizeof(int));
        free(element);
    }

    int sz = s->sz;
    for(int i = 0; i < sz; i++)
    {
        int* element = (int*)(intptr_t)pop(s);
        printf("%d ", *element);
        free(element);
    }
    freeSet(s);
    return 0;
}