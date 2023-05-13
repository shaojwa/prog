#include <iostream>
#include <unistd.h>
using namespace std;

const uint32_t COUNT=4000000000;
//int buf[COUNT];

void ptime(struct timespec *tp) {
  clock_gettime(CLOCK_REALTIME, tp);
  cout << "sec " <<  tp->tv_sec << ", nsec " << tp->tv_nsec << endl;
}
 
uint64_t pint(struct timespec begin, struct timespec end) {
  return (end.tv_sec - begin.tv_sec)*1000000000 + end.tv_nsec - begin.tv_nsec;
}


class Dog {
  public: 
    int get_age() { return _age; }
  private:
    int _age;
    string _name;
};

int main() 
{
  int *buf = (int *)malloc(COUNT * sizeof(int));
  for (uint32_t i = 0; i < COUNT; i++) {
    buf[i]=i;
  }
  //set<Dog *> dogs;
  //for (int i = 0; i < COUNT; i++) {
  //  dogs.insert(new Dog());
  //}
  struct timespec begin, end;
  ptime(&begin);
  uint32_t count = 0;
  int volatile sum = 0;
  // int  sum = 0;
  int volatile times = 0;
  while(++times < 5) {
    while (++count < COUNT) {
      //   cout << "count " << count << ", " << buf[count] << endl;
      sum += buf[count];
    }
  }
  
  //for (auto iter = dogs.begin(); iter != dogs.end(); ++iter) {
  //    sum += iter->get_age();
  //}
  ptime(&end);
  cout << "count " << count << ", sum " << sum << endl;
  uint64_t d = pint(begin, end);
  cout << d << " " << double(d)/1000000000 << endl;
  // sleep(100);
  return 0;
}

