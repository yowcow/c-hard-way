#include <assert.h>
#include <stdio.h>

int any(char [], char []);
int ok(char, char[]);

int main() {
    {
        int result = any("bizbuz", "uz");

        printf("result is 2: %d\n", result);
        assert(2 == result);
    }

    {
        int result = any("bizbuz", "efg");

        printf("result is -1: %d\n", result);
        assert(-1 == result);
    }
}

int any(char s1[], char s2[]) {
    int i;

    for (i = 0; s1[i] != 0; i++) {
        if (!ok(s1[i], s2)) {
            return i;
        }
    }

    return -1;
}

int ok(char c, char s[]) {
    int i;

    for (i = 0; s[i] != 0; i++) {
        if (s[i] == c) {
            return 0;
        }
    }

    return 1;
}
