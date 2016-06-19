#ifndef CH5_ALLOC_H
#define CH5_ALLOC_H

#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char* allocp = allocbuf;

char* ch5_alloc(int n) {
    if (allocp + n <= allocbuf + ALLOCSIZE) {
        allocp += n;
        return allocp - n;
    }

    return 0;
}

void ch5_afree(char* p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}

#endif
