#include <unistd.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <set>
#include <iostream>

using namespace std;

set<int> gset;
int MAX = 1000;
int add = 0;
int del = 0;
int gettid() {
  return syscall(SYS_gettid);
}

void* insert_routine(void *param) {
  while (add < MAX) {
    int x = rand() % MAX;
    gset.insert(x);
    add++;
    cout << "added " << add << endl;
  }
}


void* remove_routine(void *param) {
  while (del < MAX) {
    int x = rand() % MAX;
    if (gset.count(x)) {
      gset.erase(x);
      del++;
      cout << "removed " << del << endl;
    }
  }
}

int main(int argc, char *argv[]) {
  pthread_t tid_insert, tid_remove;
  pthread_create(&tid_insert, NULL, insert_routine, NULL);
  pthread_create(&tid_remove, NULL, remove_routine, NULL);
  set<int>::iterator it;
  while (del != MAX || add != MAX) {
    for (it = gset.begin(); it != gset.end(); ++it) {
      cout << "got " << *it << endl;
    }
  }
  cout << "add " << add << ", del " << del << endl;
  pthread_join(tid_insert, nullptr);
  pthread_join(tid_remove, nullptr);
  pthread_exit(nullptr);
}
