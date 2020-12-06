#include <iostream>
using namespace std;

class Dog {
	public:
		static constexpr bool m[2][2] {
			{false, true}, {true, false}
		};
		int name;
};

int main()
{
	Dog d;
	for (int i = 0; i < sizeof(Dog::m); i++) {
		int x = i / 2, y = i % 2;
		cout << "a.matrix[" << i/2 << "][" << i%2 << "] = " << Dog::m[x][1] << endl;
	}
	return 0;
}
