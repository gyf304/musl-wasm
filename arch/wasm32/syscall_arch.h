#define __SYSCALL_LL_E(x) \
((union { long long ll; long l[2]; }){ .ll = x }).l[0], \
((union { long long ll; long l[2]; }){ .ll = x }).l[1]
#define __SYSCALL_LL_O(x) __SYSCALL_LL_E((x))

__attribute__((import_module("waki"), import_name("syscall"))) long __wasm_syscall(long n, ...);

static inline long __syscall0(long n)
{
	return __wasm_syscall(n);
}

static inline long __syscall1(long n, long a)
{
	return __wasm_syscall(n, a);
}

static inline long __syscall2(long n, long a, long b)
{
	return __wasm_syscall(n, a, b);
}

static inline long __syscall3(long n, long a, long b, long c)
{
	return __wasm_syscall(n, a, b, c);
}

static inline long __syscall4(long n, long a, long b, long c, long d)
{
	return __wasm_syscall(n, a, b, c, d);
}

static inline long __syscall5(long n, long a, long b, long c, long d, long e)
{
	return __wasm_syscall(n, a, b, c, d, e);
}

static inline long __syscall6(long n, long a, long b, long c, long d, long e, long f)
{
	return __wasm_syscall(n, a, b, c, d, e, f);
}

#define IPC_64 0
