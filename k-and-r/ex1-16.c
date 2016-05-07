#include <stdint.h>
#include <stdio.h>

#define MAX_LINE 30

uint32_t _getline(char [], uint32_t*, uint32_t*);

int main() {
    char current_line[MAX_LINE];
    uint32_t length = 0;
    uint32_t current_length = 0;
    uint32_t continues = 0;

    while (_getline(current_line, &length, &continues) > 0) {
        current_length += length;

        printf("%s", current_line);

        if (!continues) {
            printf(" (Length: %u)\n", current_length);
            current_length = 0;
        }
    }

    return 0;
}

uint32_t _getline(char current_line[], uint32_t* length, uint32_t* continues) {
    char c;
    uint32_t i = 0;

    for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        current_line[i] = c;
    }

    current_line[i] = '\0';
    *length = i;
    *continues = (c == EOF || c == '\n') ? 0 : 1;

    return c == EOF ? 0 : 1;
}
