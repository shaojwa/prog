#include <iostream>
#include <unistd.h>
#include <limits.h>
using namespace std;


void show_maxs{
  cout << "PATH_MAX: " << PATH_MAX << endl;
  cout << "NAME_MAX: " << NAME_MAX << endl;
  cout << "SSIZE_MAX: " << SSIZE_MAX << endl;
}


void show_pagesize() {
  cout << "PHYS_PAGES: " << sysconf(_SC_PHYS_PAGES) << endl;
  cout << "PAGE_SIZE: " << sysconf(_SC_PAGESIZE) << endl;
}
