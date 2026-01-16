#include <stdio.h>
#include <stdlib.h> 
#include "gc.h"

size_t total_allocated = 0;
size_t total_freed = 0;

static void sweep(VM* vm);

static void mark_object(Obj* obj);

void gc(VM* vm) {
    mark_roots(vm);
    sweep(vm);
}


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

static void sweep(VM* vm) {
    Obj* curr = vm->heap;
    Obj* prev = NULL;

    while (curr != NULL) {
        if (!curr->marked) {
            /* Object is unreachable → free it */
            Obj* dead = curr;
            curr = curr->next;

            if (prev == NULL) {
                /* Removing head of heap list */
                vm->heap = curr;
            } else {
                prev->next = curr;
            }

            free(dead);
            total_freed++;
        } else {
            /* Object survives → unmark for next GC */
            curr->marked = false;
            prev = curr;
            curr = curr->next;
        }
    }
}

size_t heap_object_count(VM* vm) {
    size_t count = 0;
    Obj* curr = vm->heap;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}



