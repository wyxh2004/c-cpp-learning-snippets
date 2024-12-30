#include <cstddef>
#include <iostream>
#include <stddef.h>

#undef NULL
#ifndef __cplusplus
#define NULL ((void *)0)
#else
#define NULL                                                                   \
  0 // in c++, NULL is a null pointer constant, which may be an integral
    // constant expression rvalue of integer type that evaluates to zero (until
    // C++11) or an integer literal with value zero, or a prvalue of type
    // std::nullptr_t (since C++11)
#endif

int foo(int x);
int foo(int *p);

template <typename T> void bar(T *p) { std::cout << "bar(T*)" << std::endl; }

// full specialization
void bar(std::nullptr_t) { std::cout << "bar(nullptr_t)" << std::endl; }

void foo2(int *p) { std::cout << "foo2(int *p)" << std::endl; }

template <typename T> void baz(T ptr) { foo2(ptr); }

int main() {
  int *x = nullptr;
  int *y = NULL;
  int *z = 0;

  std::cout << x << ", " << y << ", " << z << std::endl; // 0, 0, 0

  bar(nullptr); // bar(std::nullptr_t)
  bar(NULL);    // bar(std::nullptr_t)
  bar(x);       // bar(T*)
  bar(y);       // bar(T*)
  bar(z);       // bar(T*)

  foo(NULL);    // foo(int x) or foo(int *p)? ambiguous!
  foo(nullptr); // foo(int *p) ok

  baz(nullptr); // foo(int* p)
  baz(NULL); // compile error, error: invalid conversion from ‘long int’ to
             // ‘int*’ [-fpermissive]

  return 0;
}