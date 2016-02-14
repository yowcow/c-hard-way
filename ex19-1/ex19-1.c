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
    printf("Description: %s\n", o->description);
}

void Object_destroy(void *self) {
    Object *o = self;
    free(o->description);
}

void *Object_new(size_t size, Object proto, char *description) {
    if (!proto.describe) proto.describe = Object_describe;

    Object *el = calloc(1, size);
    *el = proto;

    el->description = strdup(description);

    return el;
}

typedef struct {
    Object  proto;
    int     id;
    char*   name;
} Person;

void Person_describe(void* self) {
    Object_describe(self);

    Person *p = self;
    printf("-> Hi, I'm %s with ID %d\n", p->name, p->id);
}

void Person_destroy(void* self) {
    Object_destroy(self);
}

Object PersonProto = {
    .describe = Person_describe,
    .destroy  = Person_destroy
};

int main () {
    Person *p = Object_new(sizeof(Person), PersonProto, "ほげほげ");
    p->id = 1111;
    p->name = "あいうえい";

    p->proto.describe(p);
    p->proto.destroy(p);

    free(p);

    return 0;
}
