#include <iostream>

using namespace std;

struct node_t {
  node_t() {
    cout << "node_t::node_t()" << endl;
  }

  ~node_t() {
    cout << "node_t::~node_t()" << endl;
  }
  int n;
};

struct shape_t {
  shape_t() {
    cout << "shape_t::shape_t()" << endl;
  }
  ~shape_t() {
    cout << "shape_t::~shape_t()" << endl;
  }
  int n;
};
struct array_t {
  void print(ostream &out) {
    out << "print(ostream &out)" << endl;
  }
  ~array_t() {
    cout << "~array_t()" << endl;
  }
  shape_t s;
  node_t members[10];
};


int main() {
  array_t *ap = new array_t();
  ap->print(cout);
  delete ap;
  return 0;
}
