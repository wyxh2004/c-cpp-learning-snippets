#include <corecrt.h>
#include <cstdint>
#include <iostream>

class Base {
      public:
	virtual void show() { std::cout << "Base" << std::endl; }
};

class Derived : public Base {
      public:
	void show() override { std::cout << "Derived" << std::endl; }
};

int main() {
	// 	int a = 10;
	// 	double *p = reinterpret_cast<double *>(&a); // 强制将 int* 转换为 double*（类型不匹配）

	// 	// 这种转化没有意义，可能导致ub
	// 	std::cout << "pointer: " << p << std::endl;
	// 	std::cout << "value: " << *p << std::endl;

	// int a = 42;

	// uintptr_t address = reinterpret_cast<uintptr_t>(&a); // 将地址转换为无符号整数，常用于内存映射等
	// std::cout << "address as interger: " << address << std::endl;

	// int *p = reinterpret_cast<int *>(address);
	// std::cout << "pointer: " << p << " "
	// 	  << "value: " << *p << std::endl;

	Derived d;
	Base *basePtr = reinterpret_cast<Base *>(&d); // 将 Derived* 转换为 Base*
	basePtr->show();
	// 尽管合法，但绕过了 C++ 的类型系统，因此如果类型不匹配，可能会ub

	return 0;
}