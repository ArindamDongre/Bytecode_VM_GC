#ifndef HEAP_H
#define HEAP_H

#include "object.h"

typedef struct VM VM;

Obj* new_pair(VM* vm, Obj* left, Obj* right);

#endif
