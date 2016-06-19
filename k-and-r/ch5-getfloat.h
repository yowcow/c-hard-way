#ifndef CH5_GETFLOAT_H
#define CH5_GETFLOAT_H

#include <ctype.h>
#include <stdio.h>

int getfloat(float* pn) {
    int c, sign;
    float integer, decimal, point;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        c = getch();

        if (!isdigit(c)) {
            ungetch(c);
            return 0;
        }
    }

    integer = 0.0;
    decimal = 0.0;

    for (; isdigit(c); c = getch()) {
        integer = 10 * integer + (c - '0');
    }

    if (c == '.' && isdigit(c = getch())) {
        for (point = 0.1; isdigit(c); c = getch(), point *= 0.1) {
            decimal += point * (c - '0');
        }
    }

    *pn = sign * (integer + decimal);

    return c;
}

#endif
