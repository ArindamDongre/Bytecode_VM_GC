#ifndef OBJECT_H
#define OBJECT_H

#include <stdbool.h>

typedef struct Obj {
    bool marked;            // used by GC later
    struct Obj* left;       // reference to another object
    struct Obj* right;      // reference to another object
    struct Obj* next;       // linked list of all heap objects
} Obj;

#endif
