You can use the rpath option with the compiler to compile an executable that can load a shared library from the current directory at runtime.
```
g++ preload_test.cc -lpreload1 -lrepload2 -Wl,-rpath=. -o preload_test
```
