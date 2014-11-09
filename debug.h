/* Declarations for debug.c */
#ifndef _H_DEBUG
#define _H_DEBUG

#include <stdbool.h>
#include "types.h"

#ifdef EOF // following is only meaningful if stdio.h included
extern FILE *debugger_input;
#endif

extern bool gdb_connected;

enum DBG_REASON {
	DBG_USER,
	DBG_EXCEPTION,
	DBG_EXEC_BREAKPOINT,
	DBG_READ_BREAKPOINT,
	DBG_WRITE_BREAKPOINT,
};

void *virt_mem_ptr(u32 addr, u32 size);
void backtrace(u32 fp);
void debugger(enum DBG_REASON reason, u32 addr);
void rdebug_recv(void);
void rdebug_bind(int port);
void *debug_save_state(size_t *size);
void debug_reload_state(void *state);

#endif