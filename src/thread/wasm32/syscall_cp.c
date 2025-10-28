#include "syscall.h"

const char __cp_begin[1], __cp_end[1], __cp_cancel[1];

long __cancel();

long __syscall_cp_asm(volatile void * cancel, syscall_arg_t nr,
	syscall_arg_t u, syscall_arg_t v, syscall_arg_t w,
	syscall_arg_t x, syscall_arg_t y, syscall_arg_t z
) {
	if (*(volatile long *)cancel) {
		return __cancel();
	}
	return __syscall(nr, u, v, w, x, y, z);
}
