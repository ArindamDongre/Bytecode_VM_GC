#ifndef VM_H
#define VM_H

#include <stdint.h>
#include <stdbool.h>
#include "object.h"

#define STACK_SIZE 1024
#define MEM_SIZE 1024
#define RET_STACK_SIZE 1024

typedef enum {
    VAL_INT,
    VAL_OBJ
} ValueType;

typedef struct {
    ValueType type;
    union {
        int32_t int_val;
        Obj* obj_val;
    };
} Value;

typedef struct VM{
    Value stack[STACK_SIZE];
    int sp;

    Value memory[MEM_SIZE];

    int32_t ret_stack[RET_STACK_SIZE];
    int rsp;

    uint8_t *bytecode;
    int bytecode_size;

    int pc;
    bool running;

    Obj* heap;        // head of linked list of all heap objects
} VM;

/* VM lifecycle */
void vm_init(VM *vm);
void vm_free(VM *vm);

/* Loader */
void load_program(VM *vm, const char *filename);

/* Executor */
void execute(VM *vm);

#endif
