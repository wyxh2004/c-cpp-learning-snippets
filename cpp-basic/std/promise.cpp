#include <algorithm>
#include <chrono>
#include <future>
#include <thread>

template <class R> class promise; // 空模板类
template <class R> class promise<R &>; // 非void特化，用于在綫程閒交流對象
template <> class promise<void>; // void特化，用于交流無狀態事件

template <typename Res> class promise;
template <typename Res> class promise<Res &>;
template <> class promise<void>;

// promise 类模板是一个通用的异步结果提供者，它可以存储一个值或异常，供
// std::future 对象获取。 promise() 构造一个 promise 对象 promise(promise&& x)
// 移动构造函数 get_future() 获取与 promise 对象共享状态的 future 对象
// set_value() 设置异步结果
// set_exception() 设置异常

// future 类模板是一个通用的异步结果提供者，它可以存储一个值或异常，供
// std::promise 对象获取。 get() 获取异步结果 wait() 等待异步结果 wait_for()
// 等待异步结果，直到超时 wait_until() 等待异步结果，直到超时 valid()
// 检查异步结果是否有效 share() 共享异步结果

void add(int a, int b, std::promise<int> &&promise) {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  // set the result and the future will get the result
  printf("thread, set result\n");
  promise.set_value(a + b);
}

// -----------------------------------------

void compute_pi(const long num_steps, std::promise<double> &&promise) {
  double step = 1.0 / num_steps;
  double sum = 0.0;
  for (long i = 0; i < num_steps; ++i) {
    double x = (i + 0.5) * step;
    sum += 4.0 / (1.0 + x * x);
  }
  promise.set_value(step * sum);
}

void display(std::future<double> &&receiver) {
  double pi = receiver.get();
  printf("pi: %f\n", pi);
}

int main(void) {
  std::promise<int> promise;
  auto future = promise.get_future();

  // 用 std::move 将 promise 传递给线程
  std::thread t(add, 1, 2, std::move(promise));

  printf("main, get result\n");
  printf("result: %d\n", future.get());

  t.join();

  const int N_STEPS = 1e8;
  std::thread pi_thread1;
  std::thread pi_thread2;
  {
    std::promise<double> pi_promise;
    auto pi_receiver = pi_promise.get_future();

    pi_thread1 = std::thread(compute_pi, N_STEPS, std::move(pi_promise));
    pi_thread2 = std::thread(display, std::ref(pi_receiver));
  }

  pi_thread1.join();
  pi_thread2.join();

  return 0;
}