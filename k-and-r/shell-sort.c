#include <assert.h>
#include <stdio.h>

void shell_sort(int v[], int n);

int main() {
    int v[] = { 10, 4, 8, 9, 0, 4, 3, 10 };

    shell_sort(v, 8);

    assert(v[0] == 0);
    assert(v[1] == 3);
    assert(v[2] == 4);
    assert(v[3] == 4);
    assert(v[4] == 8);
    assert(v[5] == 9);
    assert(v[6] == 10);
    assert(v[7] == 10);

    return 0;
}

void shell_sort(int v[], int n) {
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2) {
        printf("gap: %d\n", gap);
        for (i = gap; i < n; i++) {
            printf("\ti: %d\n", i);
            for (j = i-gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {

                printf("\t\tj: %d, replacing %d (index: %d) and %d (index: %d)\n",
                    j,
                    v[j], j,
                    v[j + gap], j + gap);

                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}
