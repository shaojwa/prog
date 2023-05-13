
#include "advio.h"
#include "pth.h"
#include "lck.h"
#include "times.h"
#include "compile.h"
#include "cppl.h"
#include "mth.h"
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <unistd.h>
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
  //run_cpp_cases();
  //cout << pow2(19) << endl;
  //cout << pow3(19) << endl;
  probe_spinlock_stack();
  //iprobe_vector();
  //sleep(10);
  return 0;
}
