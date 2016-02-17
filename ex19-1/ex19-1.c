#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void (*describe)(void *self);
    void (*destroy)(void *self);
} Object;

void Object_describe(void *self) {
    printf("-> The object has nothing to describe\n");
}

void Object_destroy(void *self) {
    printf("-> Destroying an object\n");
    free(self);
}

Object ObjectProto = {
    .describe = Object_describe,
    .destroy  = Object_destroy
};

void *Object_new(size_t size, Object proto) {

    if (!proto.describe) proto.describe = ObjectProto.describe;
    if (!proto.destroy)  proto.destroy = ObjectProto.destroy;

    //Object *el = calloc(1, size);
    Object *el = malloc(size);

    *el = proto;

    return el;
}

#define NEW(T) Object_new(sizeof(T), T##Proto)
#define _(N) proto.N

//--------

typedef struct {
    Object  proto;
    int     id;
    char*   name;
} Person;

void Person_describe(void* self) {
    Person *p = self;
    printf("---> Hi, I'm %s with ID %d\n", p->name, p->id);
}

void Person_destroy(void* self) {
    Person* p = self;
    printf("---> I'm destroying a Person with ID: %d\n", p->id);
    free(p->name);
    free(p);
}

Object PersonProto = {
    .describe = Person_describe,
    .destroy  = Person_destroy,
};

Person* Person_create(int id, char* name) {

    //Person* p = Object_new(sizeof(Person), PersonProto, "人です");

    Person* p = NEW(Person);

    p->id = id;
    p->name = strdup(name);

    return p;
}

//--------

int main () {
    char* name = "あいうえ";

    {
        Person *p = Person_create(1111, name);

        p->_(describe)(p);
        p->_(destroy)(p);
    }

    {
        Person* p = Object_new(sizeof(Person), PersonProto);

        p->id = 1111;
        p->name = strdup(name);

        p->_(describe)(p);
        p->_(destroy)(p);
    }

    {
        Person *p = malloc(sizeof(Person));

        p->proto = PersonProto;
        p->id = 1111;
        p->name = strdup(name);

        p->proto.describe(p);
        p->proto.destroy(p);
    }

    return 0;
}
