#include "mm.h"

.section ".text.boot"

.globl _start
_start:
	mrs		x0, mpidr_el1
	and		x0, x0,#0xFF
	cbz		x0, master
	b		setup_stack

master:
	adr		x0, bss_begin
	adr		x1, bss_end
	sub		x1, x1, x0
	bl		memzero

setup_stack:
	mrs		x0, mpidr_el1
	and		x0, x0,#0xFF
	mov		x1, #0x1000		//define stack offset(4kb)
	mul		x1, x0, x1
	add		x1, x1, #LOW_MEMORY
	mov		sp, x1
	bl		kernel_main
	b		proc_hang

proc_hang:
	b		proc_hang
