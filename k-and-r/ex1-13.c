#include <stdint.h>
#include <stdio.h>

#define MAX_LINE 1000

uint32_t _getline(char []);
void _copy(char [], char [], uint32_t);
void _histogram(uint32_t);

int main() {
    char current_line[MAX_LINE] = { '\0' };
    char longest_line[MAX_LINE] = { '\0' };
    uint32_t length = 0;
    uint32_t longest_length = 0;

    while ((length = _getline(current_line)) > 0) {
        _histogram(length);

        if (length > longest_length) {
            _copy(current_line, longest_line, length);
            longest_length = length;
        }

        length = 0;
    }

    printf("Longest: %s (length: %u)\n", longest_line, longest_length);

    return 0;
}

void _histogram(uint32_t len) {
    printf("%5u: ", len);
    for (uint32_t i = 0; i < len; i++) {
        printf("*");
    }
    printf("\n");
}

void _copy(char from[], char to[], uint32_t len) {
    for (uint32_t i = 0; i < len; i++) {
        to[i] = from[i];
    }
}

uint32_t _getline(char current_line[]) {
    char c;
    uint32_t i = 0;

    for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        current_line[i] = c;
    }

    // A string ends with \0
    current_line[i] = '\0';

    return i;
}
