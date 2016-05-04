#include <ctype.h>
#include <stdio.h>

int atoi(char* s) {
    int i, n;

    n = 0;
    for (i = 0; *(s + i) >= '0' && *(s + i) <= '9'; i++) {
        n = 10 * n + (*(s + i) - '0');
    }

    return n;
}

int htoi(char* s) {
    int i, n;

    n = 0;
    for (i = 0; *(s + i) != 0; i++) {
        char c = toupper(*(s + i));
        int val = 0;

        if (isdigit(c)) {
            val = c - '0';
        }
        else if (isxdigit(c)) {
            val = c - 'A' + 10;
        }

        n = 16 * n + val;
    }

    return n;
}

int main() {

    {
        char* a1 = "1234";
        char* a2 = "0123";

        printf("atoi: %5s => %5d\n", a1, atoi(a1));
        printf("atoi: %5s => %5d\n", a2, atoi(a2));
    }

    {
        char* h1 = "FF";
        char* h2 = "ff";
        char* h3 = "0XFF";
        char* h4 = "0xff";

        printf("htoi: %5s => %5d\n", h1, htoi(h1));
        printf("htoi: %5s => %5d\n", h2, htoi(h2));
        printf("htoi: %5s => %5d\n", h3, htoi(h3));
        printf("htoi: %5s => %5d\n", h4, htoi(h4));
    }
}
