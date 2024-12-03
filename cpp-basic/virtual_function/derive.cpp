#include <iostream>
using namespace std;

class Base
{
public:
    virtual void my_virtual_func() {}
};

class Derive : public Base
{
public:
    virtual void my_virtual_func() {} // 重写基类的虚函数
};

// 父类指针指向子类对象
Derive derive;
Base *pBase = &derive;
pBase->my_virtual_func(); // Derive::my_virtual_func(); // 静态绑定，调用的是子类的虚函数
