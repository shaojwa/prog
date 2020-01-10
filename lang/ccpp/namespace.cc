#include <cstring>
#include <string>
#include <list>
#include <map>
#include <iostream>

using namespace std;


namespace myns {
  void traverse(map<int, string> &m);
  void map_order();
  void map_count() ;
  void stoi_abort();

  //
  struct st {
    int age;
    int height;
  };

  void get_memb();
  void get_longsize();
  void make_crash();

  typedef int (*func_bc_t) (int a, int b);
  int test(int a, int b);
  void funcptr(int argc, char **argv) ;
}


void myns::traverse(map<int, string> &m) {
  map<int, string>::iterator it;
  for (it = m.begin(); it != m.end(); ++it) {
    cout << " " << it->first;
  }
  cout << endl;
}

void myns::map_order(){
  map<int, string> m;
  m.insert(pair<int, string>(1, "one"));
  m.insert(pair<int, string>(3, "thress"));
  m.insert(pair<int, string>(9, "nine"));
  m.insert(pair<int, string>(5, "five"));
  m.insert(pair<int, string>(7, "seven"));
  traverse(m);
  m.insert(pair<int, string>(4, "four"));
  traverse(m);
  m.insert(pair<int, string>(8, "eight"));
  traverse(m);
  m.insert(pair<int, string>(6, "six"));
  traverse(m);
  m.insert(pair<int, string>(2, "two"));
  traverse(m);
}

void myns::map_count() {
  map<string, int> data;
  data["wang"] = 1;
  data["wang"] = 2;
  cout << data.count("wang") << endl;
} 

void myns::stoi_abort() {
  int num = std::stoi("one");
  cout << "num = " << num<< endl;
}

void myns::get_memb() {
  const struct st myst = { .age=31, .height=169 };
  cout << myst.age << endl;
}

void myns::get_longsize() {
  cout << "size of long = " << sizeof(long) << endl;
}

void myns::make_crash() {
  int  *p = 0 ;
  *p = 4; 
}

int myns::test(int a, int b) {
  return a + b;
}

void myns::funcptr(int argc, char **argv) {
  void *p = (void*) test;
  cout << "test = " << test << endl;
  cout << "p = " << p << endl;
  cout << "uchar at p = " << (unsigned int)(*(unsigned char *)p) << endl;
  cout << "ushort at p = " << (*(unsigned short *)p) << endl;
  cout << "uint at p = " << (*(unsigned int *)p) << endl;
  cout << ((func_bc_t)p)(1, 2) << endl; 
}
