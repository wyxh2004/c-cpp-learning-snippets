#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
int shared_source = 0;

void increment() {
  for (int i = 0; i < 10000; ++i) {
    mtx.lock(); // 锁定互斥锁，锁住互斥量
    ++shared_source;
    mtx.unlock(); // 解锁互斥锁，释放互斥量
  }
}

int main() {
  std::thread t1(increment);
  std::thread t2(increment);

  t1.join();
  t2.join();

  std::cout << "Final value of shared_source: " << shared_source << std::endl;
  return 0;
}