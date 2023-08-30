#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10
#define INCREASE_MULTIPLE_OF 2

typedef struct
{
    void **data;
    int sz;
    void *front;
    void *rear;
    int capacity;
} Queue;

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));

    q->data = (void **)malloc(sizeof(void *));
    q->sz = 0;
    q->front = NULL;
    q->rear = NULL;
    q->capacity = INITIAL_CAPACITY;
}
bool empty(Queue *q)
{
    return q->sz == 0;
}
void push(Queue *q, void *val)
{
    if (q->sz == q->capacity)
    {
        q->capacity *= INCREASE_MULTIPLE_OF;

        q->data = (void **)realloc(q->data, q->capacity * sizeof(void *));
    }
    // Add The Value in The Queue
    q->data[q->sz++] = val;
    q->rear = val;
    if (q->sz == 1)
        q->front = val;
}

void *front(Queue *q)
{
    if (q->sz == 0)
    {
        fprintf(stderr, "The queue is Empty");
    }
    return q->front;
}

void *rear(Queue *q)
{
    if (q->sz == 0)
    {
        fprintf(stderr, "The queue is Empty");
    }
    return q->rear;
}

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

    if (q->sz == 0)
    {
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        q->front = q->data[0];
        q->rear = q->data[q->sz - 1];
    }

    return removedValue;
}

int size(Queue *q)
{
    return q->sz;
}

void freeQueue(Queue* q)
{
    free(q->data);
    free(q);
}