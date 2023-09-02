#include "map.h"
#include <stdlib.h>
#include <string.h>
#include<stddef.h>
Map* createMap()
{
    Map* map = (Map*)malloc(sizeof(Map));
    if (map) {
        map->head = NULL;
        map->size = 0;
    }
    return map;
}

bool insert(Map* map, void* key, void* value)
{
    if (!map || !key)
        return false;

    // Check if the key already exists in the map
    MapNode* current = map->head;
    while (current != NULL) {
        if (current->data.key == key) {
            // Key already exists, update the value
            current->data.value = value;
            return true;
        }
        current = current->next;
    }

    // Create a new key-value pair
    MapNode* newNode = (MapNode*)malloc(sizeof(MapNode));
    if (!newNode)
        return false;

    newNode->data.key = key;
    newNode->data.value = value;
    newNode->next = map->head;
    map->head = newNode;
    map->size++;

    return true;
}

bool get(Map* map, void* key, void** value)
{
    if (!map || !key || !value)
        return false;

    MapNode* current = map->head;
    while (current != NULL) {
        if (current->data.key == key) {
            *value = current->data.value;
            return true;
        }
        current = current->next;
    }

    return false; // Key not found
}

bool removeKey(Map* map, void* key)
{
    if (!map || !key)
        return false;

    MapNode* current = map->head;
    MapNode* prev = NULL;

    while (current != NULL) {
        if (current->data.key == key) {
            if (prev == NULL) {
                map->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            map->size--;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false; // Key not found
}

bool isEmpty(Map* map)
{
    return (map == NULL) || (map->size == 0);
}

size_t getSize(Map* map)
{
    return (map == NULL) ? 0 : map->size;
}

void freeMap(Map* map)
{
    if (!map)
        return;

    MapNode* current = map->head;
    while (current != NULL) {
        MapNode* temp = current;
        current = current->next;
        free(temp);
    }

    free(map);
}
