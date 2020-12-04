#include <stdio.h>
// 
// designated inits only supported by gcc not g++
//
int main() {
	int i = 0;
	int buf[10] = { [0 ... 4] = ++i, [5 ... 9] = ++i };
	for (i = 0; i < sizeof(buf) / sizeof(buf[0]); i++) {
		printf("buf[%d] = %d\n", i, buf[i]);
	}
	return 0;
}
