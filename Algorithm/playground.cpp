#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define int long long
using namespace std;
const int N = 5e3 + 10;
int n, m, q;

signed main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x;
    int tem = x & -x;
    if (tem == x) {
      cout << -1 << endl;
    } else {
      cout << x - (x & -x) << endl;
    }
  }
}