#ifndef _SET_H_
#define _SET_H_
#include<stdbool.h>

typedef struct
{
    void** data;
    int sz;
    int capacity;
} Stack;


Stack* createStack();
bool isEmpty(Stack* stack);
void* pop(Stack* stack);
void push(Stack* stack, void* val);
int size(Stack* stack);
void* freeStack(Stack* stack);

#endif
