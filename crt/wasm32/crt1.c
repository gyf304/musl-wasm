#include <features.h>
#include <alloca.h>
#include "elf.h"
#include "libc.h"

__asm__ (
".globl __stack_pointer\n"
".globaltype __stack_pointer, i32\n"
);

weak void *__stack_pointer;

weak void _init();
weak void _fini();

weak int _main0();
weak int _main2(int argc, char **argv);
weak int _main3(int argc, char **argv, char **envp);

int __libc_start_main(int (*)(), int, char **,
	void (*)(), void(*)(), void(*)());

hidden int _main_impl(int argc, char **argv, char **envp)
{
	if (_main3) return _main3(argc, argv, envp);
	if (_main2) return _main2(argc, argv);
	if (_main0) return _main0();
	__builtin_unreachable();
}

hidden void _start_c(long *p)
{
	int argc = p[0];
	char **argv = (void *)(p+1);
	__libc_start_main(_main_impl, argc, argv, _init, _fini, 0);
}

__attribute__((export_name("_start")))
void _start() {
	register long *sp;
	__asm__ ("global.get __stack_pointer\nlocal.set %0" : "=r"(sp));
	_start_c(sp);
}

__attribute__((export_name("__main_argc_argv")))
void _main_argc_argv(int argc, char **argv)
{
	long *init_vec = alloca(sizeof(long) * (argc + 16));
	long *p = init_vec;

	*p++ = argc;

	/* argv */
	for (int i = 0; i < argc; i++) {
		*p++ = (long)argv[i];
	}
	*p++ = 0;

	/* no envp */
	*p++ = 0;

	/* basic auxv */
	*p++ = AT_PAGESZ;
	*p++ = 65536;
	*p++ = 0;
	*p++ = 0;

	_start_c(init_vec);
}
