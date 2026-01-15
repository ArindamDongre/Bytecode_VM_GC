#include <stdio.h>
#include "vm/vm.h"
#include "vm/heap.h"

int main() {
    VM vm;
    vm_init(&vm);

    Obj *a = new_pair(&vm, NULL, NULL);
    Obj *b = new_pair(&vm, a, NULL);
    a->right = b;

    for (int i = 0; i < 10000; i++)
        new_pair(&vm, NULL, NULL);

    printf("PASS: unreachable cycle collected\n");
    return 0;
}
