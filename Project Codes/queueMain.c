#include<stdio.h>
#include<stdint.h>
#include "queue.h"


int main()
{

    Queue* q = createQueue();

    for(int i = 0; i < 5; i++)
    {
        push(q, (int*)(intptr_t)(i));
    }

    printf("Queue size: %d\n", size(q));
    printf("Front element: %d\n", (int)(intptr_t)front(q));
    printf("Rear element: %d\n", (int)(intptr_t)rear(q));

    for(int i = 0; i < 5; i++)
    {
        printf("The popped Element is %d ", (int*)(intptr_t)pop(q));
    }

    return 0;
}