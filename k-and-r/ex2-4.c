#include <stdio.h>

int ok(char, char[]);
void squeeze(char s1[], char s2[]);

int main() {
    char s1[] = "bzzbbii";
    char s2[] = "bi";

    squeeze(s1, s2);

    printf("Result: %s\n", s1);

    return 0;
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

void squeeze(char s1[], char s2[]) {
    int i;
    int pack = 0;

    for (i = 0; s1[i] != 0;) {
        if (s1[i + pack] == 0) {
            s1[i] = '\0';
            break;
        }

        if (!ok(s1[i + pack], s2)) {
            pack++;
        }
        else {
            s1[i] = s1[i + pack];
            i++;
        }
    }
}
