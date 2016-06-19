#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "ch5-strcat.h"

int main() {
    char s[100] = "hoge";
    char* t = "fuga";

    ch5strcat(s, t);

    assert(strcmp(s, "hogefuga") == 0);

    return 0;
}
