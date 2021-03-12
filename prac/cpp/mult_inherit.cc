#include <iostream>
#include <map>
using namespace std;

class Person
{
  public:
    Person(): _n(32) { cout << "Person()" << endl; }
    Person(int n): _n(n) { cout << "Person(int n)" << endl; }
    ~Person() { cout << "~Person()" << endl; }
    int get_age() { return _n; }
  private:
    int _n;
};

class Lang
{
  public:
    Lang(): _lang("chinese") { cout << "Lang()" << endl; }
    Lang(string& lang): _lang(lang) { cout << "Lang(string)" << endl; }
    ~Lang() { cout << "~Lang()" << endl; }
    string& get_lang() { return _lang; }
  private:
    string _lang;
};

class Man:
public Lang,
public Person
{
};


int main()
{
    Person *pp;
    Lang *pl;
    Man *man = new Man();
    cout << "pm: " << man << endl;
    pp = static_cast<Person*>(man);
    cout << "pp: " << pp << " Age: " << pp->get_age() << endl;
    pl = static_cast<Lang*>(man);
    cout << "pl: " << pl << " Lang: " << pl->get_lang() << endl;
    return 0;
}
