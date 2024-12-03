#include <Windows.h>
#include <iostream>
#include <stdint.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")

int main() {
  HWND hwnd;
  DWORD pid;
  HANDLE handle;

  // 找到游戏主窗口的句柄
  hwnd = FindWindowA("MainWindow", "Plants vs. Zombies");
  // 获取游戏进程ID
  GetWindowThreadProcessId(hwnd, &pid);
  // 打开游戏进程
  handle = OpenProcess(PROCESS_ALL_ACCESS, false, pid);

  unsigned int pvz_base;    // 游戏基地址
  unsigned int main_object; // 主对象地址
  int32_t sun;              // 阳光值

  // 依次读取游戏内存中的基地址、主对象地址和太阳值。
  ReadProcessMemory(handle, LPCVOID(0x6a9ec0), &pvz_base, 4, nullptr);
  ReadProcessMemory(handle, reinterpret_cast<LPCVOID>(pvz_base + 0x768),
                    &main_object, 4, nullptr);
  ReadProcessMemory(handle, reinterpret_cast<LPCVOID>(main_object + 0x5560),
                    &sun, 4, nullptr);

  std::cout << "current sun: " << sun << std::endl;

  CloseHandle(handle);
  return 0;
}