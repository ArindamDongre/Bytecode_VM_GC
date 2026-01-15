# Lab 4 – Bytecode Virtual Machine

## Overview

Stack-based bytecode virtual machine with integrated garbage collector.

## Directory Structure

vm/ : VM execution engine
assembler/ : Assembly → bytecode translator
vm/gc.c : Garbage collector implementation
tests/ : VM sample programs
tests_gc/ : Garbage collection tests
include/ : Opcodes and VM headers

## Build

```bash
make
```

## Assemble

```
./assembler_exec tests/arith.asm arith.bin
```

## Run

```
./vm_exec arith.bin
```
## Running GC Tests
### Compile a GC test
```
gcc -I. tests_gc/<test_file>.c vm/vm.c vm/heap.c vm/gc.c -o <test_binary>
```

### Run
```
./<test_binary>
```

### Example 
```
gcc -I. tests_gc/gc_reachable_pair.c vm/vm.c vm/heap.c vm/gc.c -o test1
```
```
./test1

```