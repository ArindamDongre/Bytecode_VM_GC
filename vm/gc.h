#ifndef GC_H
#define GC_H

#include "vm.h"

void mark_roots(VM* vm);
void gc(VM* vm);


extern size_t total_allocated;
extern size_t total_freed;


static inline void reset_gc_counters() {
    total_allocated = 0;
    total_freed = 0;
}

#endif
