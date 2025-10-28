__asm__(
".globl __tls_base\n"
".globaltype __tls_base, i32\n"
);

int __set_thread_area(void *p) {
	__asm__ ("local.get %0\nglobal.set __tls_base" : : "r"(p));
	return 0;
}
