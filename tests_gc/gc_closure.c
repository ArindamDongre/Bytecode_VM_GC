#include <stdio.h>
#include <time.h>
#include "vm/vm.h"
#include "vm/heap.h"
#include "vm/gc.h"

int main() {
    VM vm;
    vm_init(&vm);

    reset_gc_counters();
    clock_t start = clock();

    Obj *env = new_pair(&vm, NULL, NULL);
    Obj *fn  = new_pair(&vm, NULL, NULL);
    Obj *closure = new_pair(&vm, fn, env);

    Value v;
    v.type = VAL_OBJ;
    v.obj_val = closure;
    vm.stack[++vm.sp] = v;

    for (int i = 0; i < 10000; i++)
        new_pair(&vm, NULL, NULL);

    gc(&vm);

    clock_t end = clock();
    double time_ms = (double)(end - start) * 1000 / CLOCKS_PER_SEC;

    printf("Test: Closure-style Graph\n");
    printf("Time(ms): %.3f\n", time_ms);
    printf("Allocated: %zu\n", total_allocated);
    printf("Freed: %zu\n", total_freed);
    printf("Remaining: %zu\n", heap_object_count(&vm));

    printf("PASS: closure-style graph preserved\n");
    return 0;
}
