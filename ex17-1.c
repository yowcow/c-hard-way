#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITEM_COUNT 5

struct Person {
    int id;
    char *name;
};

void Person_print(struct Person *p) {
    printf("ID: %d, Name: %s\n", p->id, p->name);
}

void create(char *filename) {
    FILE *file = fopen(filename, "w");
    int i;

    puts("=== Creating: ");

    for (i = 1; i <= ITEM_COUNT; i++) {
        struct Person *p = malloc(sizeof(struct Person));
        p->id = i;
        p->name = "ああああ";

        fwrite(p, sizeof(struct Person), 1, file);

        Person_print(p);
        free(p);
    }

    fflush(file);
    fclose(file);
}

void read(char *filename) {
    FILE *file = fopen(filename, "r+");
    int i;

    puts("=== Reading: ");

    for (i = 0; i < ITEM_COUNT; i++) {
        struct Person *p = malloc(sizeof(struct Person));

        int rc = fread(p, sizeof(struct Person), 1, file);
        if (!rc) {
            puts("Something has gone wrong at read");
            exit(1);
        }

        Person_print(p);

        free(p);
    }

    fclose(file);
}

int main() {
    char *filename = "ex17-1.dat";

    create(filename);
    read(filename);

    return 0;
}
