#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "vm.h"

Obj* new_pair(VM* vm, Obj* left, Obj* right) {
    Obj* obj = malloc(sizeof(Obj));
    if (!obj) {
        perror("malloc");
        exit(1);
    }

    obj->marked = false;
    obj->left = left;
    obj->right = right;

    // insert into heap list
    obj->next = vm->heap;
    vm->heap = obj;

    return obj;
}
