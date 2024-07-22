#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define N 200005
using namespace std;

int n, w, ans;
int s1[N], s2[N], nxt[N]; // s1是主串，s2是子串

int main() {
  cin >> n >> w;

  for (int i = 1; i <= n; i++)
    cin >> s1[i];
  for (int i = 1; i <= w; i++)
    cin >> s2[i];

  // 求差分
  for (int i = 1; i < n; i++)
    s1[i] = s1[i + 1] - s1[i];
  for (int i = 1; i < w; i++)
    s2[i] = s2[i + 1] - s2[i];

  // kmp
  for (int i = 2, j = 0; i <= w; i++) {
    while (j && s2[i] != s2[j + 1])
      j = nxt[j];
    if (s2[i] == s2[j + 1])
      j++;
    nxt[i] = j;
  }

  for (int i = 1, j = 0; i <= n; i++) {
    while (j && s1[i] != s2[j + 1])
      j = nxt[j];
    if (s1[i] == s2[j + 1])
      j++;
    if (j == w - 1)
      ans++, j = nxt[j];
  }
  cout << ans;
  return 0;
}