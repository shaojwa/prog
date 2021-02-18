20210218 p95-p104

These statements cause the given files to basically be pasted right there in the
code. You don’t need to do this with functions, because the linker can take care of
combining functions exported with .globl. However, constants defined in
another file do need to be imported in this way.
