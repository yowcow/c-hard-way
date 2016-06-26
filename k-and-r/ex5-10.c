#include <stdio.h>
#include <string.h>

float to_float(char* input) {
    float sign, result;

    sign = 1.0;
    if (*input == '-') {
        sign = -1.0;
        input++;
    }

    // Decimal is not being considered for now
    result = 0.0;
    while (*input >= '0' && *input <= '9') {
        result = result * 10 + (*input - '0');
        input++;
    }

    result = sign * result;

    return result;
}

int main(int argc, char* argv[]) {
    char* input;
    int input_length, idx, num_ptr;
    float result;

    result = 0.0;
    num_ptr = 0;
    idx = 1;
    while (--argc) {
        input = argv[idx++];
        input_length = strlen(input);

        if (input_length == 1 && *input == '+') {
            result = to_float(argv[--num_ptr]) + result;
        }
        else if (input_length == 1 && *input == '-') {
            result = to_float(argv[--num_ptr]) - result;
        }
        else if (input_length == 1 && *input == '*') {
            result = to_float(argv[--num_ptr]) * result;
        }
        else if (input_length == 1 && *input == '/') {
            result = to_float(argv[--num_ptr]) / result;
        }
        else {
            result = to_float(input);
            num_ptr++;
        }
    }

    printf("%f\n", result);

    return 0;
}
