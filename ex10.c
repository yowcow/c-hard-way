#include <stdio.h>

int main(int argc, char **argv) {
    int i = 0;

    for (i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
    int num_states = 4;
    char **states_ptr = states;

    for (i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states_ptr[i]);
    }

    int num1 = 123;
    int num2 = 234;
    int num3 = 345;
    int *numbers[] = { &num1, &num2, &num3 };

    for (i = 0; i < 3; i++) {
        printf("numbers %d: %d\n", i, *numbers[i]);
    }

    return 0;
}
