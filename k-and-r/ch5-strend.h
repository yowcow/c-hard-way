#ifndef CH5_STREND_H
#define CH5_STREND_H

#include <string.h>

int strend(char* s, char* t) {
    int i;
    int slen = strlen(s);
    int tlen = strlen(t);

    // Returns 0 if t is longer than s
    if (tlen > slen) {
        return 0;
    }

    for (i = 1; i <= tlen; i++) {
        if (*(s + slen - i) != *(t + tlen - i)) {
            return 0;
        }
    }

    return 1;
}

#endif
