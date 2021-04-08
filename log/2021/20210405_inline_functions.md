https://www.sourceware.org/gdb/onlinedocs/gdb/Inline-Functions.html

## GDB dispaly
GDB displays inlined functions just like non-inlined functions.

## HOW
For GDB to support inlined functions, the compiler must record information about inlining in the debug information。
GCC using the DWARF 2 format does this.
