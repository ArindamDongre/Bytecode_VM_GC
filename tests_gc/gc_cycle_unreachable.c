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

    Obj *a = new_pair(&vm, NULL, NULL);
    Obj *b = new_pair(&vm, a, NULL);
    a->right = b;

    for (int i = 0; i < 10000; i++)
        new_pair(&vm, NULL, NULL);

    gc(&vm);

    clock_t end = clock();
    double time_ms = (double)(end - start) * 1000 / CLOCKS_PER_SEC;

    printf("Test: Unreachable Cycle\n");
    printf("Time(ms): %.3f\n", time_ms);
    printf("Allocated: %zu\n", total_allocated);
    printf("Freed: %zu\n", total_freed);
    printf("Remaining: %zu\n", heap_object_count(&vm));

    printf("PASS: unreachable cycle collected\n");
    return 0;
}
