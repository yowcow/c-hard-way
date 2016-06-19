#include <assert.h>
#include <stdio.h>
#include "ch5-strend.h"

int main() {
    assert(strend("hogefuga", "huga") == 0);
    assert(strend("hogefuga", "fuga") == 1);
    assert(strend("fuga", "hogefuga") == 0);
    return 0;
}
