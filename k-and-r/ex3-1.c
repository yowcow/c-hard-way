#include <assert.h>
#include <stdio.h>

/* Reducing a check inside loop will result in checking all elements in array
 * even though target index is found while in the loop,
 * thus performance will be worse.
 */

int binsearch(int x, int v[], int n);

int main() {
    int v[] = { 0, 1, 2, 4, 8, 16, 32 };

    {
        int result = binsearch(2, v, 7);
        assert(result == 2);
    }

    {
        int result = binsearch(32, v, 7);
        assert(result == 6);
    }

    {
        int result = binsearch(3, v, 7);
        assert(result == -1);
    }

    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, high, mid, found;

    found = 0;
    low  = 0;
    high = n - 1;

    while (low <= high) {
        mid = (high + low) / 2;
        printf("Low: %d, High: %d, Mid: %d\n", low, high, mid);

        if (x < v[mid]) {
            high = mid - 1;
        }
        else {
            found = mid;
            low = mid + 1;
        }
    }

    return v[found] == x ? found : -1;
}
