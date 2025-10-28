#define a_barrier a_barrier
static inline void a_barrier()
{
	/* TODO implement real barrier */
	return;
}

#define a_cas a_cas
static inline int a_cas(volatile int *p, int t, int s)
{
	volatile int expected = t;
	if (__atomic_compare_exchange_n(p, &expected, s, 0, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)) {
		return t;
	}
	return expected;
}
