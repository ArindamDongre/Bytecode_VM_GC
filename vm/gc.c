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

    /* Already marked? Stop (prevents cycles) */
    if (obj->marked) return;

    /* Mark this object */
    obj->marked = true;

    /* Recursively mark referenced objects */
    mark_object(obj->left);
    mark_object(obj->right);
}


