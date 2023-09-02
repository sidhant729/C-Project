#ifndef SET_H
#define SET_H

#include <stddef.h>
#include <stdbool.h>

typedef struct
{
   void** data;
   int sz;
   int capacity; // Add capacity field to track allocated memory
} Set;

Set* createSet();
bool isEmpty(Set* s);
bool contains(Set* s, void* val);
void add(Set* s, void* val);
int size(Set* s);
Set* getUnion(Set* s1, Set* s2);
Set* getIntersection(Set* s1, Set* s2);
Set* getDifference(Set* s1, Set* s2);
void* pop(Set* s);
void freeSet(Set* s);

#endif