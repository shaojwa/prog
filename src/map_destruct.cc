#include <iostream>
#include <map>

using namespace std;

class Person
{
  public:
    Person() { cout << "Base()" << endl; }
    Person(int n): _n(n) { cout << "Base()" << endl; }
    ~Person() { cout << "~Base()" << endl; }
  private:
    int _n;
};

int main()
{
  map<string, Person> mp;
  Person b1(1), b2(2);
  cout << "---- 1 ----" << endl;
  mp["one"] = b1;
  cout << "---- 2 ----" << endl;
  mp["one"] = b2;
  cout << "---- 3 ----" << endl;
}

