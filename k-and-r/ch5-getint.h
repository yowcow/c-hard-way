#ifndef CH5_GETINT_H
#define CH5_GETINT_H

#include <ctype.h>
#include <stdio.h>
#include "ch5-buffer.h"

int getint(int* pn) {
    int c, sign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+') {
        c = getch();

        if (!isdigit(c)) {
            ungetch(c);
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}

#endif
