#include <algorithm>
#include <cstring>
#include <iostream>

const int N = 1000010;
int m, n;
char S[N], P[N];
int nxt[N];

using namespace std;
int main() {
  cin >> S + 1 >> P + 1;
  m = strlen(S + 1), n = strlen(P + 1);
  // 计算next函数
  for (int i = 2, j = 0; i <= n; i++) {
    while (j && P[i] != P[j + 1])
      j = nxt[j];
  }
  return 0;
}