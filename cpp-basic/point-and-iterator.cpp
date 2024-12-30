#include <iostream>
#include <vector>

void demoPointersAndIterators() {
  // use pointers
  int arr[] = {10, 20, 30, 40, 50};
  int *ptr = arr;

  std::cout << "使用指针:" << std::endl;
  for (int i = 0; i < 5; ++i) {
    std::cout << "指针指向的值: " << *(ptr + i) << std::endl; // deref
  }

  std::cout << "指针之间的距离: " << (ptr + 4 - ptr) << std::endl; // 4

  void (*funcPtr)() = []() {
    std::cout << "这是一个函数指针的示例。" << std::endl;
  };

  funcPtr();

  // use iterators
  std::vector<int> vec = {10, 20, 30, 40, 50};
  std::vector<int>::iterator it = vec.begin();

  std::cout << "\n使用迭代器:" << std::endl;
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << "迭代器指向的值: " << *(it + i) << std::endl; // deref
  }

  std::cout << "迭代器之间的距离: " << std::distance(it, vec.end())
            << std::endl; // 5
}

int main() {
  demoPointersAndIterators();
  return 0;
}