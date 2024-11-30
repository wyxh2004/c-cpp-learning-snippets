#include <iostream>

class Base {
public:
  virtual void print() { std::cout << "Base class" << std::endl; }
};

class Derived : public Base {
public:
  void print() override { std::cout << "Derived class" << std::endl; }
};

int main() {
  Derived derivedObj;
  Base *basePtr = &derivedObj; // 向上转型

  // 向下转型使用 static_cast (需要谨慎)
  Derived *derivedPtr = static_cast<Derived *>(basePtr);

  derivedPtr->print(); // 输出：Derived class

  int x = 10;
  double y = static_cast<double>(x); // 整型转换

  return 0;
}