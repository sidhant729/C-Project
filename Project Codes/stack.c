#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "stack.h"
#define INITIAL_CAPACITY 5
#define INCREASE_MULTIPLE_OF 2

// Stack Creation Process
Stack* createStack()
{
    // Creating The Stack;
    Stack* s = (Stack*)malloc(INITIAL_CAPACITY * sizeof(Stack));

    // Creating the Data Container Of The Stack;
    s->data = (void*)malloc(INITIAL_CAPACITY * sizeof(void));

    //Initial Size of Stack be Zero
    s->sz = 0;

    // Making Current Capacity Equal To The INITIAL_CAPACITY
    s->capacity = INITIAL_CAPACITY;

    // Return the Created Stack;
    return s;
}

// Check If the Stack is Empty or Not;
bool isEmpty(Stack* stack)
{
    return stack->sz == 0;
}
// Popping Elements From the Stack;
void* pop(Stack* stack)
{   if(isEmpty(stack))
    {
        fprintf(stderr,"Stack is Underflow");
        return NULL;
    }
    void* toReturn = stack->data[--stack->sz];
    return toReturn;
}
// Pushing The Elements In The Stack
void push(Stack* stack, void* val)
{
    // If the sz of stack is Equal to Capacity, Increase the Capacity by 2 times;
    if(stack->sz == stack->capacity)
    {
        stack->capacity *= INCREASE_MULTIPLE_OF;
        //Give the new Size to the Data Container of Stack;
        stack->data = (void*)realloc(stack->data, stack->capacity * sizeof(void));
    }
    // Put the Value in The data container;
    stack->data[stack->sz++] = val;
}
// Returns The Size of The Stack

int size(Stack* s)
{
    return s->sz;
}
// Free The Stack

void* freeStack(Stack* stack)
{
    free(stack->data);
    free(stack);
}
