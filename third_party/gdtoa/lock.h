#ifndef COSMOPOLITAN_THIRD_PARTY_GDTOA_LOCK_H_
#define COSMOPOLITAN_THIRD_PARTY_GDTOA_LOCK_H_
#include "libc/intrin/nopl.h"
#include "libc/nexgen32e/threaded.h"
#if !(__ASSEMBLER__ + __LINKER__ + 0)
COSMOPOLITAN_C_START_

int __gdtoa_lock(void);
int __gdtoa_unlock(void);

#if defined(__GNUC__) && !defined(__llvm__) && !defined(__STRICT_ANSI__)
#define __gdtoa_lock()   _NOPL0("__threadcalls", __gdtoa_lock)
#define __gdtoa_unlock() _NOPL0("__threadcalls", __gdtoa_unlock)
#else
#define __gdtoa_lock()   (__threaded ? __gdtoa_lock() : 0)
#define __gdtoa_unlock() (__threaded ? __gdtoa_unlock() : 0)
#endif

COSMOPOLITAN_C_END_
#endif /* !(__ASSEMBLER__ + __LINKER__ + 0) */
#endif /* COSMOPOLITAN_THIRD_PARTY_GDTOA_LOCK_H_ */
