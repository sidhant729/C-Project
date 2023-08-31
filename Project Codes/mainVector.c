#include <stdio.h>
#include <stdint.h>
#include "vector.h"

int main()
{
    vector* v = createVector();
    for (int i = 0; i < 5; i++) {
        push_back(v, (void*)(intptr_t)i);
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", (int)(intptr_t)(v->data[i]));
    }

    return 0;
}