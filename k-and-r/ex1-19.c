#include <stdint.h>
#include <stdio.h>

#define MAX_LINE 1000

uint32_t _getline(char [], uint32_t*);
uint32_t _length(char []);
void _reverse(char [], char []);

int main() {
    char current_line[MAX_LINE]  = { '\0' };
    uint32_t length = 0;

    while (_getline(current_line, &length) > 0) {
        char reversed_line[MAX_LINE] = { '\0' };

        _reverse(current_line, reversed_line);

        printf("%s\n", reversed_line);
    }

    return 0;
}

void _reverse(char s1[], char s2[]) {
    uint32_t i, j;
    uint32_t len = _length(s1);

    for (i = 0, j = len - 1; i < len; i++, j--) {
        s2[i] = s1[j];
    }
}

uint32_t _length(char s[]) {
    uint32_t i;

    for (i = 0; i < MAX_LINE; i++) {
        if (s[i] == '\0') {
            break;
        }
    }

    return i;
}

uint32_t _getline(char s[], uint32_t* len_ptr) {
    char c;
    uint32_t i = 0;

    for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }

    s[i] = '\0';
    *len_ptr = i;

    return c == EOF ? 0 : 1;
}
