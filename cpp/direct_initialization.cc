#include <iostream>
using namespace std;

struct Dog {
	Dog(string name_, int age_): name(name_), age(age_) {}
	string name;
	int age;
};

int main() {
	int n1(1);
	cout << "num " << n1 << endl;
	int n2{2};
	cout << "num " << n2 << endl;

	Dog d1("danny", 3);
	cout << d1.name << endl;
	Dog d2{"delta", 3};
	cout << d2.name << endl;
	return 0;
}
