#include <stdio.h>

#define MAX_LINE 1000
#define TAB_STOP 4

int _getline(char [], int*);
void _print_line(char []);
void _detab(char [], char []);

int main() {
    char s[MAX_LINE] = { '\0' };
    int len = 0;

    while (_getline(s, &len) > 0) {
        char detab_s[MAX_LINE] = { '\0' };

        _detab(s, detab_s);

        _print_line(detab_s);
    }

    return 0;
}

void _detab(char s1[], char s2[]) {
    int s1_i;
    int s2_i = 0;
    int space_count = 0;

    for (s1_i = 0; s1[s1_i] != '\0' && (s1[s1_i] == ' ' || s1[s1_i] == '\t'); s1_i++) {
        char s1_c = s1[s1_i];

        if (s1_c == ' ') {
            space_count++;
        }
        else if (s1_c == '\t') {
            space_count += TAB_STOP - space_count;
        }

        if ((space_count % TAB_STOP) == 0) {
            for (int i = 0; i < space_count; i++) {
                s2[s2_i] = ' ';
                s2_i++;
            }

            space_count = 0;
        }
    }

    // Copy remaining content
    if (s1[s1_i] != '\0') {
        for (; s1[s1_i] != '\0'; s1_i++) {
            s2[s2_i] = s1[s1_i];
            s2_i++;
        }
    }

    s2[s2_i] = '\0';
}

void _print_line(char s[]) {
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        printf("%c", s[i] == ' ' ? '_' : s[i]);
    }

    printf("\n");
}

int _getline(char s[], int* len_ptr) {
    char c;
    int i = 0;

    for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }

    s[i] = '\0';
    *len_ptr = i;

    return c == EOF ? 0 : 1;
}
