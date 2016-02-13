#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

struct Person {
    int id;
    char* name;
};

typedef struct Person person_t;
typedef void (*print_cb)(person_t* p);

void print_id(person_t* p) {
    printf("\tID: %d\n", p->id);
}

void print_name(person_t* p) {
    printf("\tName: %s\n", p->name);
}

void print_info(person_t* p, print_cb prt) {
    prt(p);
}

int main() {
    person_t p = { .id = 111, .name = "ほげほげ" };

    print_info(&p, print_id);
    print_info(&p, print_name);

    return 0;
}
