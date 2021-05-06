//
// malloc will  return out-out-memory
//
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
using namespace std;

int NUM = 1 << 2;
uint32_t size = 1 << 30;
int main() {
	void *buffs[NUM];
	cout << "MMAP_THRESHOLD " << MMAP_THRESHOLD << endl;
	cout << "NUM " << NUM << ", size " << size << endl;
	for (int i = 0; i < NUM; i++) {
		buffs[i] = malloc(size);
		if (buffs[i]) {
			cout <<  "i " << i << ", malloc success, addr " << buffs[i] << endl;
		} else {
			cout << "i " << i << ", malloc failed" << endl;
		}
	}
	return 0;
}
