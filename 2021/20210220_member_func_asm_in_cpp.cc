// 源代码
#include <iostream>

using namespace std;

class Toy {
  public:
    Toy(string &type): _type(type) {}
    Toy(char* type): _type(type) {}
    string get_type() {
      return _type;
    }
    void work() { };
  private:
    string _type;
};

class Dog {
  public:
    Dog(string &name): _name(name), _age(0) {}
    Dog(char *name): _name(name), _age(0) {}
    void play(Toy &t) {
      cout << "Im " << _name << ", " << _age << " years old"
        << ", I like play " << t.get_type() << endl;
      t.work();
    }

  private:
    int _age;
    string _name;
};

int main() {
  Dog d("danny");
  Toy t("ball");
  d.play(t);
  return 0;
}
