/**
 * Windows API 中定义的一种数据类型，
 * 其全称是 Long Pointer to Constant Void。
 * 它是一个指向常量的指针，指向的数据类型为 void。
 */
#include <minwindef.h>
#include <stdio.h>
#include <windows.h>

// 函数需要接受任意类型的指针参数时，可以使用 LPCVOID 类型
void test_function(LPCVOID lpData) {
  char *p = (char *)lpData;
  printf("%s\n", p);
}

int main() {
  char *p = "Hello World!";
  test_function(p);
  return 0;
}