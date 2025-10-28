__asm__(
".globl __tls_base\n"
".globaltype __tls_base, i32\n"
);

static inline uintptr_t __get_tp()
{
	uintptr_t tp;
	__asm__ ("global.get __tls_base\nlocal.set %0" : "=r"(tp));
	return tp;
}

#define TLS_ABOVE_TP
#define GAP_ABOVE_TP 0

#define DTP_OFFSET 0x800

#define MC_PC __gregs[0]
