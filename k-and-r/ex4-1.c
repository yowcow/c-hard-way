#include <assert.h>
#include <stdio.h>

#define MAX_LINE 1000

int strrindex(char s[], char t[]);

int main() {

    {
        char line[]    = "hohogefoohohoge";
        char pattern[] = "hoge";

        int rindex = strrindex(line, pattern);

        printf("Result: %d\n", rindex);

        assert(rindex == 11);
    }

    return 0;
}

int strrindex(char s[], char t[]) {
    int i, j, k, found;

    found = -1;

    for (i = 0; s[i] != 0; i++) {
        for (j = i, k = 0; t[k] != 0 && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == 0) {
            found = i;
        }
    }

    return found;
}
