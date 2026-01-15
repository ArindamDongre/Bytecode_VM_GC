#ifndef GC_H
#define GC_H

#include "vm.h"

void mark_roots(VM* vm);
void gc(VM* vm);


#endif
