/**
有 N 个的正整数放到数组 A 里，现在要求一个新的数组 B，新数组的第 i 个数 B[i] 是原数组 A 第 0 到第 i 个数的和。

输入：

5
1 2 3 4 5
解释
输出：

1 3 6 10 15
 */

#include <bits/stdc++.h>
using namespace std;

int A[10000], B[10000]; // A[i]表示第i个数的值，B[i]表示前i个数的和

int main()
{
    int n;

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
            B[i] = B[i - 1] + A[i];
        }

        for (int i = 0; i < n; i++)
        {
            cout << B[i] << " ";
        }
    }
    return 0;
}