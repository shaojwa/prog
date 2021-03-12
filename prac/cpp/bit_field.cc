#include <iostream>
#include <stdint.h>

using namespace std;

struct user_obj_state_t {
  uint8_t clean:1;
  uint8_t dirty:1;
  uint8_t destage:1;
  uint8_t filling:1;

  void operator=(uint8_t val) {
    clean = val & 0x1;
    dirty = (val >> 1) & 0x1;
    destage = (val >> 2) & 0x1;
    filling = (val >> 3) & 0x1;
  }
};

int main() {
  cout << "size of usre_obj_state_t " << sizeof(user_obj_state_t) << endl;
  user_obj_state_t state;
  cout << "state.clean " << (uint16_t)state.clean << endl;
  cout << "state.dirty " << (uint16_t)state.dirty << endl;
  cout << "state.destage " << (uint16_t)state.destage << endl;
  cout << "state.filling " << (uint16_t)state.filling << endl;
  cout << " set dirty and filling " << endl;
  state.dirty = 1;
  state.filling = 1;
  cout << "state.clean " << (uint16_t)state.clean << endl;
  cout << "state.dirty " << (uint16_t)state.dirty << endl;
  cout << "state.destage " << (uint16_t)state.destage << endl;
  cout << "state.filling " << (uint16_t)state.filling << endl;
  cout << " set all " << endl;
  state = 0xf;
  cout << "state.clean " << (uint16_t)state.clean << endl;
  cout << "state.dirty " << (uint16_t)state.dirty << endl;
  cout << "state.destage " << (uint16_t)state.destage << endl;
  cout << "state.filling " << (uint16_t)state.filling << endl;

  return 0;
}
