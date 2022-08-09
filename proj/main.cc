
#include "advio.h"
#include "pth.h"
#include "times.h"
#include "compile.h"
#include "cppl.h"
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
using namespace std;

int main()
{
  //show_stdno_macro();
  //read_part_select("data.in");
  //read_part_poll("data.in");
  //read_part_epoll("data.in");
  //uint16_t max = UINT16_MAX;
  //cout << "max " << max << endl;
  //race_spinlock_mutex();
  //cout << "get tsc " << get_tsc() << endl;
  run_cpp_cases();
  return 0;
}
