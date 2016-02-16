#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *description;
    void (*describe)(void *self);
    void (*destroy)(void *self);
} Object;

void Object_describe(void *self) {

    Object *o = self;

    printf("-> Description: %s\n", o->description);
}

void Object_destroy(void *self) {

    Object *o = self;

    printf("-> Destroy: %s\n", o->description);

    free(o->description);
    free(o);
}

void *Object_new(size_t size, Object proto, char *description) {

    if (!proto.describe) proto.describe = Object_describe;
    if (!proto.destroy)  proto.destroy = Object_destroy;

    Object *el = calloc(1, size);
    *el = proto;

    el->description = strdup(description);

    return el;
}

#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)
#define _(N) proto.N

//--------

typedef struct {
    Object  proto;
    int     id;
    char*   name;
} Person;

void Person_describe(void* self) {

    Person *p = self;

    // Do default "describe"
    Object_describe(self);

    // Do *my* "describe"
    printf("---> Hi, I'm %s with ID %d\n", p->name, p->id);
}

void Person_destroy(void* self) {

    Person* p = self;

    // Do *my* "destroy"
    printf("---> I'm destroying a Person with ID: %d\n", p->id);
    free(p->name);

    // Do default "destroy"
    Object_destroy(self);
}

Object PersonProto = {
    .describe = Person_describe,
    .destroy  = Person_destroy,
};

Person* Person_create(int id, char* name) {

    //Person* p = Object_new(sizeof(Person), PersonProto, "人です");

    Person* p = NEW(Person, "Person とは人です");

    p->id = id;
    p->name = strdup(name);

    return p;
}

//--------

int main () {

    Person *p = Person_create(1111, "おなまえ");

    //p->proto.describe(p);
    //p->proto.destroy(p);

    p->_(describe)(p);
    p->_(destroy)(p);

    return 0;
}
