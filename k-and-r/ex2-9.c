#include <assert.h>
#include <stdio.h>

/*
 * Right most bit disappears because taking & on decremented number deletes original bit.
 * For example, if x is 12:
 *
 *                *
 *  12   => 0000 1100
 *  12-1 => 0000 1011
 *  -----------------
 *  &       0000 1000 => 8
 *                *
 *               *
 *  8    => 0000 1000
 *  8-1  => 0000 0111
 *  -----------------
 *  &       0000 0000 => 0
 *               *
 */

int bitcount(unsigned int x);

int main() {

    assert(bitcount(12) == 2);
    assert(bitcount(15) == 4);

    return 0;
}

int bitcount(unsigned int x) {
    int b;

    for (b = 0; x != 0; x = x & (x - 1)) {
        b++;
    }

    return b;
}
