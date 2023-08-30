#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#define INITIAL_CAPACITY 5
#define INCREASE_MULTIPLE_OF 2

typedef struct 
{
    int capacity;
    int sz;
    void** data;
} vector;

// Vector Creation Process
vector* createVector()
{
    vector* v = (vector*) malloc(INITIAL_CAPACITY * sizeof(vector));
    v->data = (void**) malloc(INITIAL_CAPACITY * sizeof(void*));

    v->sz = 0;
    v->capacity = INITIAL_CAPACITY;

    return v;
}

// Empty Or Not;
bool isEmpty(vector*  v)
{
    return v->sz == 0;
}

void push_back(vector* v, void* val)
{
    if(v->sz == v->capacity)
    {
        v->capacity *= INCREASE_MULTIPLE_OF;
        v->data = (void**) realloc(v->data, v->capacity*sizeof(void*));
    }
    v->data[v->sz++] = val;

}

void* pop_back(vector* v)
{
    if(isEmpty(v))
    {
        fprintf(stderr, "Vector array is empty.\n");
        return NULL;
    }
    void* toReturn = v->data[--v->sz];
    return toReturn;
}

void erase(vector* v)
{
    while(v->sz--)
    {
        pop_back(v);
    }
}

int size(vector* v)
{
    return v->sz;
}