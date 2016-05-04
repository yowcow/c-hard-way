#include <stdio.h>

int atoi(char* s) {
    int i, n;

    n = 0;
    for (i = 0; *(s + i) != 0; i++) {
        n = 10 * n + (*(s + i) - '0');
    }

    return n;
}

int main() {
    char* s1 = "1234";
    char* s2 = "0123";

    printf("%s => %d\n", s1, atoi(s1));
    printf("%s => %d\n", s2, atoi(s2));
}
