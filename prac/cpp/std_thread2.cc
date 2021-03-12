#include <thread> 
#include <mutex>
#include <iostream>
#include <condition_variable>

const int THREADS_COUNT = 3;
const int TIMES = 10;
std::mutex g_mtx;
std::condition_variable cond_var;

void work(int n, int *pcount) {
  for (int i = 0; i < TIMES; ++i) {
    std::unique_lock<std::mutex> l(g_mtx);
    cond_var.wait(l, [n, pcount](){ return n == *pcount; });
    std::cout << char('A' + n);
    *pcount = ++(*pcount) % THREADS_COUNT;
    cond_var.notify_all();
  }
}
int main() {
  int count = 0;
  std::thread work_threads[THREADS_COUNT];
  for(int i = 0; i < THREADS_COUNT; i++) {
    work_threads[i] = std::thread(work, i, &count);
  }
  for (auto &t: work_threads) {
    t.join();
  }
  return 0;
}



		

