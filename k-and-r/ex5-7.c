#include <stdio.h>
#include <string.h>
#include "ch5-alloc.h"

#define MAXLINES 100

int  getline    (char*, int);
int  readlines  (char** lineptr, int maxlines);
void qsort      (char** v, int left, int write);
void swap       (char** v, int i, int j);
void writelines (char** lineptr, int nlines);

int main() {
    int nlines;
    char* lineptr[MAXLINES];

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("Error: Too many lines\n");
        return 1;
    }
}

#define MAXLEN 100

int readlines(char** lineptr, int maxlines) {
    int len, nlines;
    char line[MAXLEN], *p;

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = ch5_alloc(len + 1)) == NULL) {
            return -1;
        }
        else {
            strcpy(p, line);
            *(lineptr + nlines++) = p;
        }
    }

    return nlines;
}

int getline(char* line, int maxlen) {
    int i, c;

    for (i = 0; i < maxlen && ((c = getchar()) != '\n'); i++) {
        *(line + i) = c;
    }

    *(line + i) = '\0';

    printf("getline() => Line: %s, length: %d\n", line, i);

    return i;
}

void qsort(char* v[], int left, int right) {
    char* pivot;
    int min, max;

    if (left >= right) {
        return;
    }

    min = left;
    max = right;
    pivot = v[((min + max) / 2)];

    printf("min: %d, max: %d\n", min, max);

    for (; min < max; min++) {
        if (strcmp(v[min], pivot) >= 0) {
            for (; min < max && strcmp(v[max], pivot) > 0; max--)
                ;
            if (strcmp(v[max], pivot) <= 0) {
                swap(v, min, max);
            }
        }
    }

    qsort(v, left, min - 1);
    qsort(v, min, right);
}

void swap(char** v, int i, int j) {
    char* temp;

    temp = *(v + i);
    *(v + i) = *(v + j);
    *(v + j) = temp;
}

void writelines(char** lineptr, int nlines) {
    int i;

    for (i = 0; i < nlines; i++) {
        printf("Line %d: %s\n", i, *(lineptr + i));
    }
}
