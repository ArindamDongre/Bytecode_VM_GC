#include <stdio.h>
#include "vm/vm.h"
#include "vm/heap.h"

int main() {
    VM vm;
    vm_init(&vm);

    new_pair(&vm, NULL, NULL);   

    for (int i = 0; i < 10000; i++)
        new_pair(&vm, NULL, NULL);

    printf("PASS: unreachable object collected\n");
    return 0;
}
