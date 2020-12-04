https://gcc.gnu.org/onlinedocs/gcc/Designated-Inits.html

#### Designated Initializers
Standard C90 requires the elements of an initializer to appear in a fixed order, the same as the order of the elements in the array or structure being initialized.

In ISO C99 you can give the elements in any order, specifying the array indices or structure field names they apply to, and GNU C allows this as an extension in C90 mode as well. This extension is not implemented in GNU C++.

If the value in it has side effects, the side effects happen only once, not for each initialized field by the range initializer.

#### waht is side-effects-once 
```
#include <stdio.h>
// designated inits only supported by gcc not g++
int main() {
	int i = 0;
	int buf[10] = { [0 ... 4] = ++i }; 
  // here i = 1 not 5, that is increment once not 5 times
	for (i = 0; i < sizeof(buf) / sizeof(buf[0]); i++) {
		printf("buf[%d] = %d\n", i, buf[i]);
	}
	return 0;
}
```

#### structure initializer
In a structure initializer, specify the name of a field to initialize with ‘.fieldname =’ before the element value.
