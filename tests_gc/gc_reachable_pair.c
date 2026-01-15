#include <stdio.h>
#include "vm/vm.h"
#include "vm/heap.h"

int main() {
    VM vm;
    vm_init(&vm);

    Obj *p = new_pair(&vm, NULL, NULL);

    Value v;
    v.type = VAL_OBJ;
    v.obj_val = p;
    vm.stack[++vm.sp] = v;   

    for (int i = 0; i < 10000; i++) {
        new_pair(&vm, NULL, NULL);
    }
    if (vm.stack[vm.sp].obj_val == p) {
        printf("PASS: reachable object survived GC\n");
    } else {
        printf("FAIL: reachable object lost\n");
    }

    return 0;
}
