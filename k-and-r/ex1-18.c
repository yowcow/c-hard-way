#include <stdint.h>
#include <stdio.h>

#define MAX_LINE 1000

uint32_t _getline(char [], uint32_t*);
uint32_t _trimline(char [], uint32_t);

int main() {
    char current_line[MAX_LINE];
    uint32_t length = 0;

    while (_getline(current_line, &length) > 0) {
        length = _trimline(current_line, length);

        if (length > 0) {
            printf("%5u: \"%s\"\n", length, current_line);
        }
    }

    return 0;
}

uint32_t _trimline(char current_line[], uint32_t length) {
    char c;
    uint32_t i, new_length;
    new_length = length;

    for (i = 1; i <= length; i++) {
        c = current_line[length - i];

        if (c == ' ' || c == '\t') {
            current_line[length - i] = '\0';
            new_length--;
        }
        else {
            break;
        }
    }

    return new_length;
}

uint32_t _getline(char current_line[], uint32_t* length_ptr) {
    char c;
    uint32_t i = 0;

    for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        current_line[i] = c;
    }

    current_line[i] = '\0';
    *length_ptr = i;

    return c == EOF ? 0 : 1;
}
