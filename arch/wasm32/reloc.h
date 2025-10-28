__attribute__((import_module("sys"), import_name("crtjmp"))) long __wasm_crtjmp(void *pc, void *sp);

#define LDSO_ARCH "wasm32"

#define TPOFF_K 0

#define CRTJMP(pc,sp) __wasm_crtjmp(pc, sp)
