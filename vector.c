#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 10
#define INCREASE_MULTIPLE_OF 2
vector* createVector()
{
    vector* v = (vector*) malloc(sizeof(vector));
    v->data = (void*) malloc(INITIAL_CAPACITY * sizeof(void));
    v->sz = 0;
    v->capacity = INITIAL_CAPACITY;

    return v;
}

bool isEmpty(vector* v)
{
    return v->sz == 0;
}

void push_back(vector* v, void* val)
{
    if (v->sz == v->capacity) {
        v->capacity *= INCREASE_MULTIPLE_OF;
        v->data = (void*) realloc(v->data, v->capacity * sizeof(void));
    }
    v->data[v->sz++] = val;
}
void* pop_back(vector* v)
{
    if (isEmpty(v)) {
        fprintf(stderr, "Vector array is empty.\n");
        return NULL;
    }
    void* toReturn = v->data[--v->sz];
    return toReturn;
}
int size(vector* v)
{
    return v->sz;
}

void freeVector(vector* v)
{
    free(v->data);
    free(v);

}
