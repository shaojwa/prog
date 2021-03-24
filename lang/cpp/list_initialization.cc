// initializes an object from braced-init-list
//
#include <iostream>
using namespace std;

struct Dog {
	Dog(string name_, int age_): name(name_), age(age_) {}
	string name;
	int age;
};

int main() {
	int n2{2};
	cout << "num " << n2 << endl;
	Dog d2{"delta", 3};
	cout << d2.name << endl;
	return 0;
}
