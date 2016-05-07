#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

void expand(char s1[], char s2[]);

int main() {
    {
        char s1[] = "a-e";
        char s2[MAX_LINE] = { '\0' };

        expand(s1, s2);

        printf("Result: %s\n", s2);
        assert(strcmp(s2, "abcde") == 0);
    }

    {
        char s1[] = "a-e1-5";
        char s2[MAX_LINE] = { '\0' };

        expand(s1, s2);

        printf("Result: %s\n", s2);
        assert(strcmp(s2, "abcde12345") == 0);
    }

    {
        char s1[] = "a-e-j";
        char s2[MAX_LINE] = { '\0' };

        expand(s1, s2);

        printf("Result: %s\n", s2);
        assert(strcmp(s2, "abcdefghij") == 0);
    }
}

void expand(char s1[], char s2[]) {
    int i, j;
    char from, to, tmp;

    from = to = tmp = '\0';
    j = 0;

    for (i = 0; s1[i] != 0; i++) {
        if (from == 0) {
            from = s1[i];
        }
        else if (from != 0 && s1[i] != '-') {
            to = s1[i];
        }

        if (from != 0 && to != 0) {
            for (tmp = from; tmp <= to; tmp++, from = tmp) {
                s2[j++] = tmp;
            }

            to = 0;

            if (s1[i + 1] != '-') {
                from = 0;
            }
        }
    }
}
