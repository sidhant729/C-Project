#ifndef VEC_H
#define VEC_H

#include <stdbool.h>

typedef struct vector {
    int capacity;
    int sz;
    void** data;
} vector;

vector* createVector();
bool isEmpty(vector* v);
void push_back(vector* v, void* val);
void* pop_back(vector* v);
void erase(vector* v);
int size(vector* v);
void freeVector(vector* v);
#endif