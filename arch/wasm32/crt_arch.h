weak int main(int argc, char **argv, char **envp);
weak void _init();
weak void _fini();


__asm__ (
".globl __stack_pointer\n"
".globaltype __stack_pointer, i32\n"
// also export __stack_pointer
".export_name __stack_pointer,__stack_pointer\n"
);

int __libc_start_main(int (*)(), int, char **,
	void (*)(), void(*)(), void(*)());

#ifdef SHARED
/* _dlstart_c is defined as _start_c */
hidden void _dlstart_c(size_t *sp, size_t *dynv);

__attribute__((export_name("_dlstart")))
void _dlstart() {
	register long *sp;
	__asm__ ("global.get __stack_pointer\nlocal.set %0" : "=r"(sp));
	_dlstart_c(sp, 0);
}
#else
/* regular _start_c */
hidden void _start_c(long *p);

__attribute__((export_name("_start")))
void _start() {
	register long *sp;
	__asm__ ("global.get __stack_pointer\nlocal.set %0" : "=r"(sp));
	_start_c(sp);
}

#endif
