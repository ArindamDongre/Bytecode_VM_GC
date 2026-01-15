#include <stdio.h>
#include <time.h>
#include "vm/vm.h"
#include "vm/heap.h"
#include "vm/gc.h"

int main() {
    VM vm;
    vm_init(&vm);

    total_allocated = 0;
    total_freed = 0;

    clock_t start = clock();

    // Test Logic 
    Obj *p = new_pair(&vm, NULL, NULL);

    Value v;
    v.type = VAL_OBJ;
    v.obj_val = p;
    vm.stack[++vm.sp] = v;   

    for (int i = 0; i < 10000; i++) {
        new_pair(&vm, NULL, NULL);
    }

    gc(&vm); // trigger GC

    clock_t end = clock();
    double time_ms = (double)(end - start) * 1000 / CLOCKS_PER_SEC;

    // Benchmark 
    printf("Test: Reachable Pair\n");
    printf("Time(ms): %.3f\n", time_ms);
    printf("Allocated: %zu\n", total_allocated);
    printf("Freed: %zu\n", total_freed);
    printf("Remaining: %zu\n", heap_object_count(&vm));


    if (vm.stack[vm.sp].obj_val == p) {
        printf("PASS: reachable object survived GC\n");
    } else {
        printf("FAIL: reachable object lost\n");
    }

    return 0;
}
