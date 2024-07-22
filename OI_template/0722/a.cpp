#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define N 100010
using namespace std;

typedef unsigned long long ULL;
ULL h[N], ans[N]; // p[i] = P ^ i, h[i] = s[1~i]的hash值
const int P = 131;
int n, m; // n个数
char s[N];

ULL calc(char *s, int n) {
  h[0] = 0;
  for (int i = 1; i <= n; i++) {
    h[i] = h[i - 1] * P + s[i];
  }
  return h[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;

  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    int m = strlen(s + 1);
    ans[i] = calc(s, m);
  }
  sort(ans + 1, ans + n + 1);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (ans[i] != ans[i - 1])
      cnt++;
  }
  cout << cnt << endl;
  return 0;
}