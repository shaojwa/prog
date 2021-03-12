#include <cstring>
#include <string>
#include <list>
#include <map>
#include <iostream>

using namespace std;

struct object_t {
  public:
    object_t() {
      cout << " object_t() " << endl;
    }
    object_t(object_t &o) {
      cout << " object_t(const object_t &o) " << endl;
      name = o.name;
      age = o.age;
    }
    string name;
    int age;
};

struct user_t {
  object_t& get_obj_ref() {
    return obj;
  }
  object_t get_obj() {
    return obj;
  }

  object_t obj;
};

void process_ref(object_t &obj) {
  cout << obj.name << endl;
}

void process_value(object_t obj) {
  cout << obj.name << endl;
}


int main (int argc, char * argv[])
{
  user_t u;
  u.get_obj(); // 1 times of call object_t(object_t &o)
  process_value(u.get_obj());
  //process_ref(u.get_obj_ref()); // 0 times of call object_t(object_t &o)
  return 0;
}
