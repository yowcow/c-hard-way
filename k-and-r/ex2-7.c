#include <assert.h>
#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);

int main() {

    {
        // 0111 1010 -> invert 4, 3
        // 0000 1010 (== 10)
        unsigned int result = invert(122, 4, 3);

        printf("result == %u\n", result);
        assert(result == 10);
    }

    {
        // 0111 1010 -> invert 1, 3
        // 0111 0100 (== 116)
        unsigned int result = invert(122, 1, 3);

        printf("result == %u\n", result);
        assert(result == 116);
    }

    return 0;
}

unsigned int invert(unsigned int x, int p, int n) {

    // Create a mask with inverting bits flagged
    unsigned int mask = ~(~0 << n) << p;

    // Do XOR to invert bits in x
    return x ^ mask;
}
