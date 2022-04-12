
#ifndef ADV_IO_H_
#define ADV_IO_H_

#include <string>
using namespace std;

void  show_stdno_macro();
int read_part_epoll(const string &filename);
int read_part_poll(const string &filename);
int check_select_retval(const string &filename);
int read_part_select(const string &filename);

#endif
