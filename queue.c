#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include "queue.h"

#define INITIAL_CAPACITY 10
#define INCREASE_MULTIPLE_OF 2


// Create A Queue
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->sz = 0;
    q->front = NULL;
    q->rear = NULL;
    q->capacity = INITIAL_CAPACITY;
    q->data = (void **)malloc(sizeof(void *)*q->capacity );

}
// Returns True if Queue Is Empty Else Returns False
bool empty(Queue *q)
{
    return q->sz == 0;
}

// Add The Element In The Queue
void push(Queue *q, void *val)
{
    if (q->sz == q->capacity)
    {
        q->capacity *= INCREASE_MULTIPLE_OF;

        q->data = (void **)realloc(q->data, q->capacity * sizeof(void *));
    }

    q->data[q->sz] = val;
    q->sz++;
    q->rear = val;
    if (q->sz == 1)
        q->front = val;
}
// Returns The Element which is In Front Of Queue
void *front(Queue *q)
{
    if (q->sz == 0)
    {
        fprintf(stderr, "The queue is Empty");
        return NULL;
    }
    return q->front;
}
// Returns The Element Which Is in The back Of The Queue
void *rear(Queue *q)
{
    if (q->sz == 0)
    {
        fprintf(stderr, "The queue is Empty");
    }
    return q->rear;
}
// Remove and Returns The Element Which is In The front
void *pop(Queue *q)
{
    if (q->sz == 0)
    {
        fprintf(stderr, "Underflow -> The queue is Empty");
        return NULL;
    }

    void *removedValue = q->data[0];
    memmove(q->data, q->data + 1, (q->sz - 1) * sizeof(void *));
    q->sz--;

    q->data[q->sz] = NULL;

    return removedValue;
}

// Returns The Size of Queue
int size(Queue *q)
{
    return q->sz;
}
// Free The Space 
void freeQueue(Queue* q)
{
    free(q->data);
    free(q);
}