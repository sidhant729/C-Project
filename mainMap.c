#include "map.h"
#include <stdio.h>
#include<stddef.h>
#include<stdbool.h>
int main()
{
    Map* map = createMap();

    int key1 = 1;
    int value1 = 42;

    insert(map, &key1, &value1);

    int* retrievedValue;
    if (get(map, &key1, (void**)&retrievedValue)) {
        printf("Key: %d, Value: %d\n", key1, *retrievedValue);
    } else {
        printf("Key not found.\n");
    }

    freeMap(map);

    return 0;
}
