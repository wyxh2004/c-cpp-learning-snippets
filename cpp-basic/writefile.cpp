#include <cstring>
#include <fileapi.h>
#include <handleapi.h>
#include <iostream>
#include <minwindef.h>
#include <windows.h>

int main() {
  HANDLE hFile = CreateFile("example.txt",         // 文件名
                            GENERIC_WRITE,         // 写权限
                            0,                     // 不共享
                            NULL,                  // 默认安全属性
                            CREATE_ALWAYS,         // 文件不存在则创建
                            FILE_ATTRIBUTE_NORMAL, // 普通文件
                            NULL);                 // 无模板文件
  if (hFile == INVALID_HANDLE_VALUE) {
    std::cerr << "CreateFile failed" << std::endl;
    return -1;
  }

  // 要写入的数据
  const char *data = "Hello, WriteFile!";
  DWORD bytesWritten;

  // 写入文件
  if (!WriteFile(hFile, data, strlen(data), &bytesWritten, NULL)) {
    std::cerr << "WriteFile failed" << std::endl;
  }

  std::cout << "Successfully Written " << bytesWritten << " bytes" << std::endl;

  // 关闭文件句柄
  CloseHandle(hFile);

  return 0;
}
