the order of the lib to link determines the function which to use in preload_test:
```
$ g++ preload_test.cc -lpreload1 -lrepload2 -Wl,-rpath=. -o preload_test
$ ./preload_test
1
$ g++ preload_test.cc -lpreload2 -lrepload1 -Wl,-rpath=. -o preload_test
$ ./preload_test
2
```
