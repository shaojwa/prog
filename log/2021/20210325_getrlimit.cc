//
//
#include <sys/resource.h>
#include <iostream>
using namespace std;

int NUM = 1 << 2;
uint32_t size = 1 << 30;
int main() {
	cout << "RLIM_INFINITY "  << RLIM_INFINITY << endl; // 2^64-1
  rlimit rl;
	int ret =  getrlimit(RLIMIT_CORE, &rl);
	cout << "RLIMIT_CORE rl.rlim_cur "  << rl.rlim_cur << endl;  // 2^64-1
	cout << "RLIMIT_CORE rl.rlim_max "  << rl.rlim_max << endl;  // 2^64-1
	ret =  getrlimit(RLIMIT_CPU, &rl);
	cout << "RLIMIT_CPU rl.rlim_cur "  << rl.rlim_cur << endl;  // 2^64-1
	cout << "RLIMIT_CPU rl.rlim_max "  << rl.rlim_max << endl;  // 2^64-1
	ret =  getrlimit(RLIMIT_DATA, &rl);
	cout << "RLIMIT_DATA rl.rlim_cur "  << rl.rlim_cur << endl;  // 2^64-1
	cout << "RLIMIT_DATA rl.rlim_max "  << rl.rlim_max << endl;  // 2^64-1
	ret =  getrlimit(RLIMIT_FSIZE, &rl);
	cout << "RLIMIT_FSIZE rl.rlim_cur "  << rl.rlim_cur << endl;  // 2^64-1
	cout << "RLIMIT_FSIZE rl.rlim_max "  << rl.rlim_max << endl;  // 2^64-1
	ret =  getrlimit(RLIMIT_DATA, &rl);
	cout << "RLIMIT_NOFILE rl.rlim_cur "  << rl.rlim_cur << endl;  // 2^64-1
	cout << "RLIMIT_NOFILE rl.rlim_max "  << rl.rlim_max << endl;  // 2^64-1
	ret =  getrlimit(RLIMIT_STACK, &rl);
	cout << "RLIMIT_STACK rl.rlim_cur "  << rl.rlim_cur << endl;  // 8M
	cout << "RLIMIT_STACK rl.rlim_max "  << rl.rlim_max << endl;  // 2^64-1
	ret =  getrlimit(RLIMIT_AS, &rl);
	cout << "RLIMIT_AS rl.rlim_cur "  << rl.rlim_cur << endl;  // 2^64-1
	cout << "RLIMIT_AS rl.rlim_max "  << rl.rlim_max << endl;  // 2^64-1
	return 0;
}
