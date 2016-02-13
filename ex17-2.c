#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    int   id;
    char* name;
};

struct List {
    struct Person* p;
    struct List* next;
};

typedef struct Person Person_t;
typedef struct List List_t;

void print_people(List_t* list) {
    printf("--> ID: %d, Name: %s\n", list->p->id, list->p->name);

    if (list->next) {
        print_people(list->next);
    }
}

void free_people(List_t* list) {
    if (list->next) {
        free_people(list->next);
    }

    free(list->p);
    free(list);
}

int main() {

    List_t* l1 = (List_t*) malloc(sizeof(List_t));
    l1->p = (Person_t*) malloc(sizeof(Person_t));
    l1->p->id = 111;
    l1->p->name = "ほげほげ";
    l1->next = NULL;

    List_t* l2 = (List_t*) malloc(sizeof(List_t));
    l2->p = (Person_t*) malloc(sizeof(Person_t));
    l2->p->id = 222;
    l2->p->name = "ふがふが";
    l2->next = NULL;
    l1->next = l2;

    List_t* l3 = (List_t*) malloc(sizeof(List_t));
    l3->p = (Person_t*) malloc(sizeof(Person_t));
    l3->p->id = 333;
    l3->p->name = "ほげふが";
    l3->next = NULL;
    l2->next = l3;

    print_people(l1);
    free_people(l1);

    return 0;
}
