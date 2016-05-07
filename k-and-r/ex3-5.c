#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

void itob(unsigned int n, char s[], int b);
void reverse(char s[]);

int main() {

    {
        char s[MAX_LINE];

        itob(13, s, 2);

        printf("Result: %s\n", s);
        assert(strcmp(s, "1101") == 0);
    }

    {
        char s[MAX_LINE];

        itob(255, s, 16);

        printf("Result: %s\n", s);
        assert(strcmp(s, "ff") == 0);
    }

    {
        char s[MAX_LINE];

        itob(15, s, 10);

        printf("Result: %s\n", s);
        assert(strcmp(s, "15") == 0);
    }

    return 0;
}

void itob(unsigned int n, char s[], int b) {
    int i, mod;

    i = 0;
    do {
        mod = n % b;
        s[i++] = mod < 10 ? mod + '0' : mod - 10 + 'a';
    } while ((n /= b) > 0);

    reverse(s);
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
