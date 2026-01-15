#ifndef HEAP_H
#define HEAP_H

#include "object.h"

typedef struct VM VM;

Obj* new_pair(VM* vm, Obj* left, Obj* right);

extern size_t total_allocated;
extern size_t total_freed;


size_t heap_object_count(VM* vm);

#endif
