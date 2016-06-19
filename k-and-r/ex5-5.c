#include <assert.h>
#include <stdio.h>
#include <string.h>

void _strncpy(char* s, char* t, int n) {
    int i;

    for (i = 0; i < n; i++) {
        *s++ = *t++;
    }

    *s = '\0';
}

void _strncat(char* s, char* t, int n) {
    int i;

    while (*s != '\0')
        s++;

    for (i = 0; i < n; i++) {
        *s++ = *t++;
    }

    *s = '\0';
}

int _strncmp(char* s, char* t, int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (*s++ != *t++) {
            return *s - *t;
        }
    }

    return 0;
}

int main() {
    char array[10];

    {
        printf("== Test _strncpy ...\n");

        array[0] = '\0';

        _strncpy(array, "hogefuga", 4);

        assert(strcmp(array, "hoge") == 0);

        _strncpy(array, "hogefuga", 2);

        assert(strcmp(array, "ho") == 0);
    }

    {
        printf("== Test _strncat ...\n");

        array[0] = '\0';

        _strncat(array, "hogefuga", 4);

        assert(strcmp(array, "hoge") == 0);

        _strncat(array, "hogefuga", 2);

        assert(strcmp(array, "hogeho") == 0);
    }

    {
        printf("== Test _strncmp ...\n");

        assert(_strncmp("hogefuga", "hogehoge", 4) == 0);
        assert(_strncmp("hogefuga", "hogehoge", 5) > 0);
        assert(_strncmp("hogehoge", "hogefuga", 5) < 0);
    }

    return 0;
}
