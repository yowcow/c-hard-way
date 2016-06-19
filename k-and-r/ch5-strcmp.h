#ifndef CH5_STRCMP_H
#define CH5_STRCMP_H

int strcmp(char *s, char *t) {
    for (; *s == *t; s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}

#endif
