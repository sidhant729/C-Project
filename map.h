#ifndef MAP_H
#define MAP_H

#include <stdbool.h>
#include<stddef.h>
// Define a key-value pair structure
typedef struct {
    void* key;
    void* value;
} KeyValuePair;

// Define the map structure
typedef struct MapNode {
    KeyValuePair data;
    struct MapNode* next;
} MapNode;

typedef struct {
    MapNode* head;
    size_t size;
} Map;

// Function to create a new map
Map* createMap();

// Function to insert a key-value pair into the map
bool insert(Map* map, void* key, void* value);

// Function to retrieve the value associated with a key
bool get(Map* map, void* key, void** value);

// Function to remove a key-value pair from the map
bool removeKey(Map* map, void* key);

// Function to check if the map is empty
bool isEmpty(Map* map);

// Function to get the size of the map
size_t getSize(Map* map);

// Function to free the map and its elements
void freeMap(Map* map);

#endif
