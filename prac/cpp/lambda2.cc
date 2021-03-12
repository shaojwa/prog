#include <functional>
#include <iostream>
using namespace std;

class Math {
  public:
    Math(int num): _num(num){}
    std::function<int (int)> get_div() {
      return [this](int value) { return value / _num; };
    }

    int(*get_double())(int) {
      return [](int value) { return value << 1; };
    }

  private:
    int _num;
};

int main() {
  Math *pf = new Math(2);
  // func1
  std::function<int(int)> func1;
  func1 = pf->get_div();
  // func2
  int (*func2)(int) = nullptr;
  func2 = pf->get_double();
  // test
  cout << func1(1) << endl;
  cout << func2(2) << endl;
  return 0;
}

