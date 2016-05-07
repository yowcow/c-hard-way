#include <assert.h>
#include <stdio.h>

unsigned char bit2char(char* bit);
unsigned char rightrot(unsigned char x, int n);

int main() {

    unsigned char result = rightrot(bit2char("01010110"), 3);

    printf("result == %d\n", result);
    assert(result == bit2char("11001010"));

    return 0;
}

unsigned char bit2char(char* bit) {
    unsigned char n, i;

    n = 0;
    for (i = 0; bit[i] != 0; i++) {
        n = 2 * n + (bit[i] == '1' ? 1 : 0);
    }

    return n;
}

unsigned char rightrot(unsigned char x, int n) {
    unsigned char mask = ~0;
    unsigned char right_bit_on = 01;
    unsigned char left_bit_on  = ~(mask >> 1);
    int i;

    for (i = 0; i < n; i++) {
        if ((x | right_bit_on) == x) {
            // right most bit is 1
            x >>= 1;
            x |= left_bit_on;
        }
        else {
            // right most bit is not 1
            x >>= 1;
        }
    }

    return x;
}
