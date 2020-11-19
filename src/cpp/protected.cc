#include <iostream>

using namespace std;

class Person {
    public:
        void say() {
            cout << "i say" << endl;
        }
    public:
        virtual void did() = 0;
    private:
        void think() {
            cout << "i think" << endl;
        }

    private:
        string name;
        int age;
};

class Adult: public Person {
    public: 
        void show() {
            cout << "i show" << endl;
        }
        void did() override {
            cout << "i did it " << endl;
        }
};

class Dad: Adult {
    public:
        void comment() {
            cout << "i comment" << endl;
            did();
        }
};

int main() {
    Person *ps;
    Adult ad;
    ps = &ad;
    ps->did();
    return 0;
}

