#include<stdio.h>
#include "stackUpdated.h"


int main()
{

    Stack* s = createStack();
    for(int i = 0; i < 50; i++)
    {
        push(s, (void*)(intptr_t)i);
    }

    while(!isEmpty(s))
    {
        printf("%d ", (int)(intptr_t)pop(s));
    }
    
    Stack* s2 = createStack();
    for(char i = 'a'; i <= 'z'; i++)
    {
        push(s, (void*)(intptr_t)i);
    }

    while(!isEmpty(s))
    {
        printf("%c ", (char)(intptr_t)pop(s));
    }

    return 0;
}