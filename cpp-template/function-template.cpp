#include <iostream>

// template <typename T> T max(T a, T b) { return a > b ? a : b; }

// int main() {
//   int a{10};
//   int b{20};
//   std::cout << max(a, b) << std::endl;
//   std::cout << max<double>(10, 20) << std::endl;

//   double c{10.5};
//   double d{20.5};
//   std::cout << max(c, d) << std::endl;

//   char e{'a'};
//   char f{'b'};
//   std::cout << max(e, f) << std::endl;

//   return 0;
// }

// 使用引用传递。参数是只读的
// template <typename T> T max(const T &a, const T &b) { return a > b ? a : b; }

// int main() {
//   int a{10};
//   int b{20};
//   std::cout << max(a, b) << std::endl; // 输出 20

//   std::string s1{"apple"};
//   std::string s2{"banana"};
//   std::cout << max(s1, s2) << std::endl; // 输出 banana

//   // 临时对象
//   std::cout << max(10, 20) << std::endl; // 输出 20
//   std::cout << max(std::string("apple"), std::string("banana"))
//             << std::endl; // 输出 banana

//   return 0;
// }