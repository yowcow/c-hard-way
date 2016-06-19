#ifndef CH5_STRCAT_H
#define CH5_STRCAT_H

void ch5strcat(char* s, char* t) {
    while (*s != '\0')
        s++;

    while (*t != '\0')
        *s++ = *t++;

    *s = '\0';
}

#endif
