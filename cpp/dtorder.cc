#include <iostream>
#include <cstdint>
using namespace std;

class Dog {
	string _name;
	uint8_t _age;
public:
	Dog(): _name("danny"), _age(3) {
		cout << __func__ << endl;
	}
	Dog(string name, uint8_t age): _name(name), _age(age) {
		cout << __func__ << endl;
	}
	~Dog() {
		cout << __func__ << endl;
	}
};

class Sheep {
	string _name;
	uint8_t _age;
public:
	Sheep(): _name("suse"), _age(6) {
		cout << __func__ << endl;
	}
	Sheep(string name, uint8_t age): _name(name), _age(age) {
		cout << __func__ << endl;
	}
	~Sheep() {
		cout << __func__ << endl;
	}
};

class Home {
	Dog dog;
	Sheep sheep;
public:
   Home(): dog("d", 6), sheep("su", 12) {}
};


int main() {
   Home h;
	 return 0;
}
