#include <thread> 
#include <mutex>
#include <iostream>
#include <condition_variable>

// using namespace std;

const int THREADS_COUNT = 3;
const int TIMES = 10;
std::mutex g_mtx;
std::condition_variable cond_var;
int counter = 0;

void work(int n) {
  for (int i = 0; i < TIMES; ++i) {
    std::unique_lock<std::mutex> l(g_mtx);
    cond_var.wait(l, [n](){ return n == counter; });
    std::cout << char('A' + n);
    counter = ++counter % THREADS_COUNT;
    cond_var.notify_all();
  } 
}
int main() {
  int counter = 0;
  std::thread work_threads[THREADS_COUNT];
  for(int i = 0; i < THREADS_COUNT; i++) {
    work_threads[i] = std::thread(work, i);
  }
  for (auto &t: work_threads) {
    t.join();
  }
  std::cout << "primary thread exit" << std::endl;
  return 0;
}


		

