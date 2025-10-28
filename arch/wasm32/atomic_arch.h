#define a_barrier a_barrier
static inline void a_barrier()
{
	/* TODO implement real barrier */
	return;
}

#define a_cas a_cas
static inline int a_cas(volatile int *p, int t, int s)
{
	/* TODO implement real CAS */
	int old = *p;
	if (old == t) {
		*p = s;
	}
	return old;
}
