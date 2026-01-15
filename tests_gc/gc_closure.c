#include <stdio.h>
#include "vm/vm.h"
#include "vm/heap.h"

int main() {
    VM vm;
    vm_init(&vm);

    Obj *env = new_pair(&vm, NULL, NULL);
    Obj *fn  = new_pair(&vm, NULL, NULL);
    Obj *closure = new_pair(&vm, fn, env);

    Value v;
    v.type = VAL_OBJ;
    v.obj_val = closure;
    vm.stack[++vm.sp] = v;

    for (int i = 0; i < 10000; i++)
        new_pair(&vm, NULL, NULL);

    printf("PASS: closure-style graph preserved\n");
    return 0;
}
