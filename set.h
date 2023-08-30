#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct 
{
   void** data;
   int sz; 
}Set;

Set* createSet()
{
    Set* s = (Set*) malloc(sizeof(Set));
    s->sz = 0;
    s->data = (void*) malloc(sizeof(void*));
    return s;
}

bool isEmpty(Set* s)
{
    return s->sz == 0;
}

bool contains(Set* s, void* val, size_t size)
{
    for (int i = 0; i < s->sz; i++)
    {
        if (memcmp(s->data[i], val, size) == 0)
            return true;
    }
    return false;
}

void add(Set* s, void* val, size_t size)
{
    if (!contains(s, val, size))
    {
        s->data = realloc(s->data, sizeof(void*) * (s->sz + 1));
        s->data[s->sz] = malloc(size);
        memcpy(s->data[s->sz], val, size);
        s->sz++;
    }
}
int size(Set* s)
{
    return s->sz;
}

Set* getUnion(Set* s1, Set* s2)
{
    Set* newSet = createSet();

    for(int i = 0; i < s1->sz; i++)
    {
        add(newSet, s1->data[i], sizeof(s2->data[i]));
    }
    for(int j = 0; j < s2->sz; j++)
    {
        add(newSet, s2->data[j], sizeof(s2->data[j]));
    }
    return newSet;
}

Set* getIntersection(Set* s1, Set* s2)
{
    Set* newSet = createSet();
    for(int i = 0; i < s1->sz; i++)
    {
        for(int j = 0; j < s2->sz; j++)
        {
            if(s1->data[i] == s2->data[j])
            {
                add(newSet, s1->data[i], sizeof(s1->data[i]));
            }
        }
    }
}

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
        if(isPresent == false) add(newSet, s1->data[i], sizeof(s1->data[i]));
    }
}
void* pop(Set* s)
{
    if (s->sz == 0) return NULL; 
    
    void* curr = s->data[s->sz - 1]; 
    s->sz--;
    return curr;
}

void freeSet(Set* s)
{
    for(int i = 0; i < s->sz; i++)
    {
        free(s->data[i]);
    }
    free(s->data);
    free(s);
}