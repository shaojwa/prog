#### using g++
using g++ to build:
```
g++ -fPIC -shared -o inline.so inline_foo.cc inline_bar.cc
-rwxrwxr-x 1 wsh wsh 13160 Dec 10 22:28 inline.so
```
using gcc to build:
```
-rwxrwxr-x 1 wsh wsh 13256 Dec 10 22:29 inline.so
```
file type
```
[wsh@dev ~/wsh/prog/src/cpp]$ file inline.so
inline.so: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), 
dynamically linked, BuildID[sha1]=45b2e30883f60223e138cc2e9ffa3966446dde50, not stripped
```

#### why -shared
```
-shared
  Produce a shared object which can then be linked with other objects to form an executable.
```
#### why fPIC
```
[wsh@dev ~/wsh/prog/src/cpp]$ gcc -shared -o inline.so inline_foo.cc inline_bar.cc
/usr/bin/ld: /tmp/cceZMvHm.o: relocation R_X86_64_32 against `.rodata' 
can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: /tmp/ccarUXbo.o: relocation R_X86_64_32 against `.rodata' 
can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: final link failed: Nonrepresentable section on output
collect2: error: ld returned 1 exit status
```

#### func symbol
```
[wsh@dev ~/wsh/prog/src/cpp]$ nm inline.so  | grep foo
0000000000000ac5 T _Z3foov
[wsh@dev ~/wsh/prog/src/cpp]$ nm inline.so  | grep bar
0000000000000c0e T _Z3barv
```
T: The symbol is in the text (code) section.

#### no symbol of inline func get_hight()
```
[wsh@dev ~/wsh/prog/src/cpp]$ nm inline.so  | grep get_hight
[wsh@dev ~/wsh/prog/src/cpp]$
```

#### removing inline cause the error-report
```
[wsh@dev ~/wsh/prog/src/cpp]$ g++ -fPIC -shared -o inline.so inline_foo.cc inline_bar.cc
/tmp/cchRqVdT.o: In function `Dog::get_name()':
inline_bar.cc:(.text+0x0): multiple definition of `Dog::get_name()'
/tmp/ccPB10Cw.o:inline_foo.cc:(.text+0x0): first defined here
collect2: error: ld returned 1 exit status
[wsh@dev ~/wsh/prog/src/cpp]$ gcc -fPIC -shared -o inline.so inline_foo.cc inline_bar.cc
/tmp/cc1GKlnq.o: In function `Dog::get_name()':
inline_bar.cc:(.text+0x0): multiple definition of `Dog::get_name()'
/tmp/ccMpkE06.o:inline_foo.cc:(.text+0x0): first defined here
collect2: error: ld returned 1 exit status
```
pay atterntion of `mutiple  definition`, not the `redefinition` in compile

#### build static lib
build static lib is NOT means using -static which is used to build WITH the static lib but not generate static lib
```
[wsh@dev ~/wsh/prog/src/cpp]$ gcc -static -o inline.a inline_foo.cc inline_bar.cc
/usr/bin/ld: cannot find -lstdc++
/usr/bin/ld: cannot find -lm
/usr/bin/ld: cannot find -lc
collect2: error: ld returned 1 exit status
```
#### the difference of symbolic in static and shared lib
```
[wsh@dev ~/wsh/prog/src/cpp]$ nm inline.so | grep foo
0000000000000ac5 T _Z3foov
[wsh@dev ~/wsh/prog/src/cpp]$ nm inline.so | grep bar
0000000000000c0e T _Z3barv
[wsh@dev ~/wsh/prog/src/cpp]$ nm inline.a | grep foo
inline_foo.o:
0000000000000000 T _Z3foov
[wsh@dev ~/wsh/prog/src/cpp]$ nm inline.a | grep bar
inline_bar.o:
0000000000000000 T _Z3barv
```
#### two identical symbol in static lib 
```
[wsh@dev ~/wsh/prog/src/cpp]$ nm inline.a | grep get_name
0000000000000000 T _ZN3Dog8get_nameEv
0000000000000000 T _ZN3Dog8get_nameEv
```
but this case can not be allowed in shared lib because the shared-lib is linked

#### inline function is weak
```
[wsh@dev ~/wsh/prog/src/cpp]$ nm inline.a | grep get_name
0000000000000000 W _ZN3Dog8get_nameEv
0000000000000000 W _ZN3Dog8get_nameEv
[wsh@dev ~/wsh/prog/src/cpp]$ nm inline.so | grep get_name
0000000000000bca W _ZN3Dog8get_nameEv
```
