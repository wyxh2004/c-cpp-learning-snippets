#include <iostream>
using namespace std;
// virtual function
// virtual table (vptb)
// virtual table pointer (vptr)
class Base
{
    // public:
    //     void func1() {}
    //     void func2() {}

public:
    // virtual void vfunc1() {}
    // virtual void vfunc2() {}
    virtual void my_virtual_func() {}
    //     virtual ~Base() {}

    // private:
    //     unsigned int m_a;
    //     unsigned int m_b;
};

int main()
{
    // 16 = 8 + 4 + 4
    // cout << "sizeof(a)=" << sizeof(Base) << endl;

    Base *base1 = new Base();
    base1->my_virtual_func(); // 多态
    Base base2;
    base2.my_virtual_func(); // 非多态
    Base *base3 = &base2;
    base3->my_virtual_func(); // 多态
    return 0;
}
