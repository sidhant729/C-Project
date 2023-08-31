#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "set.h"

// Set Creation Process
Set* createSet()
{
    // Create A Set
    Set* s = (Set*) malloc(sizeof(Set));
    s->sz = 0;
    // Put Initial Capacity as 4.
    s->capacity = 4;
    // Create A data Array.
    s->data = (void*) malloc(sizeof(void) * s->capacity);
    return s;
}

// isEmpty -> If Set is Empty Return True Else Return False;
bool isEmpty(Set* s)
{
    return s->sz == 0;
}

// To Check If a Particular Element Is Present In Set Or Not
bool contains(Set* s, void* val)
{
    for (int i = 0; i < s->sz; i++)
    {
        if (memcmp(s->data[i], val, sizeof(void*)) == 0)
            return true;
    }
    return false;
}

// Add an Element To The Set
void add(Set* s, void* val)
{
    if (!contains(s, val))
    {
        if (s->sz >= s->capacity)
        {
            s->capacity *= 2;
            s->data = realloc(s->data, sizeof(void*) * s->capacity);
        }

        s->data[s->sz] = malloc(sizeof(void*));
        memcpy(s->data[s->sz], val, sizeof(void*));
        s->sz++;
    }
}
// Union Of Two Sets
Set* getUnion(Set* s1, Set* s2)
{
    Set* newSet = createSet();

    for(int i = 0; i < s1->sz; i++)
    {
        add(newSet, s1->data[i]);
    }
    for(int j = 0; j < s2->sz; j++)
    {
        add(newSet, s2->data[j]);
    }
    return newSet;
}

// Common Of Two Sets
Set* getIntersection(Set* s1, Set* s2)
{
    Set* newSet = createSet();
    for(int i = 0; i < s1->sz; i++)
    {
        for(int j = 0; j < s2->sz; j++)
        {
            if(s1->data[i] == s2->data[j])
            {
                add(newSet, s1->data[i]);
            }
        }
    }
}
// Difference Of Two Sets
Set* getDifference(Set* s1, Set* s2)
{
    Set* newSet = createSet();
    for(int i = 0; i < s1->sz; i++)
    {
        bool isPresent = false;
        for(int j = 0; j < s2->sz; j++)
        {
            if(s1->data[i] == s2->data[j])
            {
                isPresent = true;
            }
        }
        if(isPresent == false) add(newSet, s1->data[i]);
    }
}

// Returns The Size of The Set
int size(Set* s)
{
    return s->sz;
}

// Remove A Element From The Set
void* pop(Set* s)
{
    if (s->sz == 0) return NULL;

    void* curr = s->data[s->sz - 1];
    s->sz--;
    return curr;
}


// Free The Set
void freeSet(Set* s)
{
    for(int i = 0; i < s->sz; i++)
    {
        free(s->data[i]);
    }
    free(s->data);
    free(s);
}
