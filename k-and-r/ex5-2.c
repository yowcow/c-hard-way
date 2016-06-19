#include <stdio.h>
#include "ch5-buffer.h"
#include "ch5-getfloat.h"

#define SIZE 10

int main() {
    float array[SIZE] = {0.0};
    int i, n;

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;

    for (i = 0; i < n; i++) {
        printf("Item %d: %5.4f\n", i, array[i]);
    }

    return 0;
}
