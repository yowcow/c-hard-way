#include <assert.h>
#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main() {
    return 0;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {

    unsigned int mask = x >> p & ~(~0 << n);

    y = y & mask;

    x = x | y;

    return x;
}
