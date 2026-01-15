#include "gc.h"
#include <stdio.h>

static void mark_object(Obj* obj);

/*
 * Mark all objects reachable from the VM stack.
 */
void mark_roots(VM* vm) {
    for (int i = 0; i <= vm->sp; i++) {
        Value v = vm->stack[i];

        if (v.type == VAL_OBJ && v.obj_val != NULL) {
            // mark_object will be implemented next
            mark_object(v.obj_val);
        }
    }
}

static void mark_object(Obj* obj) {
    if (obj == NULL) return;

    // Temporary stub: just mark the object
    obj->marked = true;
}

