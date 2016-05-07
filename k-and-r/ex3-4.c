#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

void reverse(char s[]);
void itoa(int n, char s[]);

int main() {
    {
        char s[MAX_LINE];

        itoa(43209, s);

        printf("Result: %s\n", s);
        assert(strcmp(s, "43209") == 0);
    }

    return 0;
}

void reverse(char s[]) {
    int i, j, len;
    char tmp;

    len = strlen(s);
    j   = len - 1;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        tmp  = s[j];
        s[j] = s[i];
        s[i] = tmp;
    }
}

void itoa(int n, char s[]) {
    int i;

    if (n < 0) {
        n = -n;
    }

    for (i = 0; n > 0; i++, n /= 10) {
        s[i] = n % 10 + '0';
    }

    s[i] = '\0';

    reverse(s);
}
