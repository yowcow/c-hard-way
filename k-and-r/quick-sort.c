#include <stdio.h>

void print_array(int* items, int len) {
    int i;

    for (i = 0; i < len; i++) {
        printf(" %d ", items[i]);
    }

    printf("\n");
}

void swap(int* v, int i, int j) {
    int tmp = *(v + i);
    *(v + i) = *(v + j);
    *(v + j) = tmp;
}

void qsort(int v[], int left, int right) {
    int min, max, pivot;

    if (left >= right) {
        return;
    }

    min = left;
    max = right;
    pivot = v[((left + right) / 2)];

    for (; min < max; min++) {
        if (v[min] >= pivot) {
            for (; min < max && v[max] > pivot; max--)
                ;

            if (v[max] <= pivot) {
                swap(v, min, max);
            }
        }
    }

    qsort(v, left, min - 1);
    qsort(v, min, right);
}

int main() {

    {
        int items[8] = { 8, 4, 3, 7, 6, 5, 2, 1 };
        print_array(items, 8);
        qsort(items, 0, 7);
        print_array(items, 8);
    }

    {
        int items[3] = { 9, 1, 2 };
        print_array(items, 3);
        qsort(items, 0, 2);
        print_array(items, 3);
    }

    return 0;
}
