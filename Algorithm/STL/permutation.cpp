/**
 * hdu 1027 全排列
 * 给我们两个数字，N和M。我们应该编程找出由1到N组成的第M个最小序列。
 */

#include <bits/stdc++.h>
using namespace std;

int a[1001];
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
            a[i] = i;
        int b = 1;
        do
        {
            if (b == m)
                break;
        } while (next_permutation(a + 1, a + n + 1));
        for (int i = 1; i < n; i++)
            cout << a[i] << " "; // 输出第m大的字典序
        cout << a[n] << endl;
    }
    return 0;
}