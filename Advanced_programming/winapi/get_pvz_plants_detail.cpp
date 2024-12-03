#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#include <initializer_list>
#include <iostream>

#include <Windows.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")

#ifdef _WIN64
static_assert(sizeof(uintptr_t) == 8,
              "uintptr_t should be 8 bytes on 64-bit systems");
#else
static_assert(sizeof(uintptr_t) == 4,
              "uintptr_t should be 4 bytes on 32-bit systems");
#endif

HWND hwnd = nullptr;     // 窗口句柄
DWORD pid = 0;           // 进程标识
HANDLE handle = nullptr; // 进程句柄

// 查找游戏窗口打开进程句柄
bool FindGame() {
  hwnd = FindWindowW(L"MainWindow", L"Plants vs. Zombies");
  if (hwnd == nullptr)
    return false;

  GetWindowThreadProcessId(hwnd, &pid);
  if (pid == 0)
    return false;

  handle = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
  return handle != nullptr;
}

// 关闭游戏进程句柄
void CloseGame() {
  if (handle != nullptr)
    CloseHandle(handle);
}

// 读取内存的函数模板
template <typename T> T ReadMemory(std::initializer_list<uintptr_t> addr) {
  T result = T();
  uintptr_t buffer = 0;
  for (auto it = addr.begin(); it != addr.end(); it++) {
    if (it != addr.end() - 1) {
      SIZE_T read_size = 0;
      int ret = ReadProcessMemory(handle, (const void *)(buffer + *it), &buffer,
                                  sizeof(buffer), &read_size);
      if (ret == 0 || sizeof(buffer) != read_size)
        return T();
    } else {
      SIZE_T read_size = 0;
      int ret = ReadProcessMemory(handle, (const void *)(buffer + *it), &result,
                                  sizeof(result), &read_size);
      if (ret == 0 || sizeof(result) != read_size)
        return T();
    }
  }
  return result;
}
int main(int argc, char const *argv[]) {
  std::wcout.imbue(std::locale("chs"));

  if (!FindGame())
    return -1;

  // 读取阳光数值
  auto sun = ReadMemory<int>({0x6a9ec0, 0x768, 0x5560});
  std::wcout << L"当前阳光: " << sun << std::endl;

  // 读取场上植物信息
  auto plants_offset = ReadMemory<unsigned int>({0x6a9ec0, 0x768, 0xac});
  auto plants_count_max = ReadMemory<unsigned int>({0x6a9ec0, 0x768, 0xb0});
  for (size_t i = 0; i < plants_count_max; ++i) {
    auto plant_dead = ReadMemory<bool>({plants_offset + 0x141 + 0x14c * i});
    auto plant_squished = ReadMemory<bool>({plants_offset + 0x142 + 0x14c * i});
    auto plant_type = ReadMemory<int>({plants_offset + 0x24 + 0x14c * i});
    auto plant_row = ReadMemory<int>({plants_offset + 0x1c + 0x14c * i});
    auto plant_col = ReadMemory<int>({plants_offset + 0x28 + 0x14c * i});
    if (!plant_dead && !plant_squished)
      std::wcout << L"序号: " << i << L" " << L"类型: " << plant_type << L" "
                 << L"所在行: " << (plant_row + 1) << L" " << L"所在列: "
                 << (plant_col + 1) << L" " << std::endl;
  }
  auto plants_next_pos = ReadMemory<unsigned int>({0x6a9ec0, 0x768, 0xb8});
  auto plants_count = ReadMemory<unsigned int>({0x6a9ec0, 0x768, 0xbc});
  std::wcout << L"下一个未被占用的植物位置: " << plants_next_pos << std::endl;
  std::wcout << L"当前植物总数: " << plants_count << std::endl;

  CloseGame();
  return 0;
}
