#include <iostream>
using namespace std;


enum op_t {
	OP_RD,
	OP_WR,
	OP_RW,
	OP_MAX
};

int matrix[][OP_MAX] = {
	[OP_RD] = {0, 0, 1},
	[OP_WR] = {0, 1, 1},
	[OP_RW] = {1, 1, 1}
};
int buf[10] = {[0] = 0, [1] = [0], [0] = 1};
int main() {
	cout << "buf[1]" << buy[1] << endl;
	int x, y;
	do {
		cin >> x >> y;
		if (x == -1 && y == -1) {
			break;
		}
		cout << "[" << x << "," << y << "]=" << matrix[x % OP_MAX][y % OP_MAX] <<  endl; 
	} while (true);
	return 0;
}
