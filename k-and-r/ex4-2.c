#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

#define MAX_LINE 1000

double atof(char s[]);

int main() {
    {
        double result = atof("1");

        printf("Result is %lf\n", result);

        assert(result == 1.0);
    }

    {
        double result = atof("1.234");

        printf("Result is %lf\n", result);

        assert(result == 1.234);
    }

    {
        double result = atof("-1.234");

        printf("Result is %lf\n", result);

        assert(result == -1.234);
    }

    {
        double result = atof("123.45e-6");

        printf("Result is %lf\n", result);

        assert(result == 123.45e-6);
    }

    return 0;
}

double atof(char s[]) {
    double val, power, exp;
    int i, sign, exp_sign;

    i     = 0;
    power = 1.0;
    sign = s[i] == '-' ? -1 : 1;

    exp      = 0.0;
    exp_sign = 1;

    if (s[i] == '-' || s[i] == '+') { i++; }

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.') {
        i++;

        for (power = 1.0; isdigit(s[i]); i++) {
            val = 10.0 * val + (s[i] - '0');
            power *= 10.0;
        }
    }

    if (s[i] == 'e' || s[i] == 'E') {
        i++;

        exp_sign = s[i] == '-' ? -1 : 1;
        i++;

        for (; isdigit(s[i]); i++) {
            exp = 10.0 * exp + (s[i] - '0');
        }
    }

    return (sign * val / power) * pow(10.0, exp_sign * exp);
}
