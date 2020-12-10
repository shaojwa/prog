#include "inline_test.h"


string bar() {
  Dog d(string("bar"));
  return d.get_name();
}
