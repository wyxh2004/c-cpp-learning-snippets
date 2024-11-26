#include <iostream>

// 必须显式的指明类模板的类型实参，并且没有办法推导，事实上这个空类在这里本身没什么意义。
template <typename T> struct Test {};
// 或许我们可以这样
template <typename T> struct Test1 {
  T t;
};

template <typename T> struct Test2 {
  Test2(T v) : t{v} {}

private:
  T t;
};

// 类模板参数推导
// 对于简单的类模板，通常可以普通的类似函数模板一样的自动推导
template <class T> struct Test3 {
  Test3(T, T);
};

template <class T> struct Test4 {
  Test4(const T &, const T &); // 同样的可以像函数模板那样加上许多的修饰
};

int main() {

  Test<int> t1;
  Test<double> t2;
  // Test t; // Error!
  // Test1 t4{1}; // C++17 OK！
  Test2 t3{1};
  auto y = new Test3{1, 2}; // 分配的类型是 Test3<int>

  return 0;
}