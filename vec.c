#include<stdio.h>
#include"vec.h"

int main()
{   
    vector* v = createVector();
    for(int i = 0; i < 5; i++)
    {
        push_back(v, (char*)(intptr_t)(i));
    }

    for(int i = 0; i < 5; i++)
    {
        int data = 
        printf("%c ",(char*)(intptr_t)(v->data[i]));
    }


    return 0;
}