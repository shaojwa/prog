#include <iostream>
#include <stdint.h>

using namespace std;

union obj_state_t {
  struct {
    uint8_t clean:1;
    uint8_t dirty:1;
    uint8_t destage:1;
    uint8_t filling:1;
  };
  uint8_t val;
  void operator=(uint8_t v) {
    val = v;
  }
};

int main() {
  cout << "size of usre_obj_state_t " << sizeof(obj_state_t) << endl;
  obj_state_t state;
  cout << "state.val " << (uint16_t)state.val << endl;
  cout << "state.clean " << (uint16_t)state.clean << endl;
  cout << "state.dirty " << (uint16_t)state.dirty << endl;
  cout << "state.destage " << (uint16_t)state.destage << endl;
  cout << "state.filling " << (uint16_t)state.filling << endl;
  cout << "set dirty and filling " << endl;
  state.dirty = 1;
  state.filling = 1;
  cout << "state.val " << (uint16_t)state.val << endl;
  cout << "state.clean " << (uint16_t)state.clean << endl;
  cout << "state.dirty " << (uint16_t)state.dirty << endl;
  cout << "state.destage " << (uint16_t)state.destage << endl;
  cout << "state.filling " << (uint16_t)state.filling << endl;
  cout << "set all " << endl;
  state = 0xf;
  cout << "state.val " << (uint16_t)state.val << endl;
  cout << "state.clean " << (uint16_t)state.clean << endl;
  cout << "state.dirty " << (uint16_t)state.dirty << endl;
  cout << "state.destage " << (uint16_t)state.destage << endl;
  cout << "state.filling " << (uint16_t)state.filling << endl;

  return 0;
}
