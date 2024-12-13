// #include <iostream>
// #include <mutex>
// #include <thread>

// std::recursive_mutex rmtx;
// int shared_resource = 0;

// // 递归函数
// void recursive_increment(int count) {
//   if (count <= 0)
//     return;
//   std::lock_guard<std::recursive_mutex> lock(rmtx); // 上锁，保证线程安全
//   ++shared_resource;
//   std::cout << "Incremented shared_resource to " << shared_resource
//             << " (count = " << count << ")" << std::endl;

//   recursive_increment(count - 1);
// }

// int main() {
//   std::thread t1(recursive_increment, 3); // 线程 t1 执行
//   recursive_increment(3) std::thread t2(recursive_increment, 3); // 线程 t2
//   执行 recursive_increment(3)

//   t1.join();
//   t2.join();

//   std::cout << "Final shared_resource value: " << shared_resource <<
//   std::endl;

//   return 0;
// }
include<mutex> std::mutex mtx;
void thread_function() {
      std::lock_guard<std::mutex> lock(mtx);
       // 访问共享资源}