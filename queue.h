#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    void **data;
    int sz;
    void *front;
    void *rear;
    int capacity;
} Queue;

Queue* createQueue();
bool empty(Queue* q);
void push(Queue* q, void* val);
void* front(Queue* q);
void* rear(Queue* q);
void* pop(Queue* q);
int size(Queue* q);
void freeQueue(Queue* q);

#endif