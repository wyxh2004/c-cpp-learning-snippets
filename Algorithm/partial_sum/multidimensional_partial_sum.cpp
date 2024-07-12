/**
 * 二维差分
 * 对二维数组a，其差分s为一个二维数组
 * s[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1]
 * s[i][j]的二位前缀和为a[i][j]
 * 用于子矩阵修改和求和
 */

/**
 * 在一个 n * m 的只包含 0 和 1 的矩阵里找出一个不包含 0 的最大正方形，输出边长。
 */
#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];
int b[1000][1000];
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        for (unsigned int i = 0; i < n; i++)
        {
            for (unsigned int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                b[i][j] = a[i][j] - (i > 0 ? b[i - 1][j] : 0) - (j > 0 ? b[i][j - 1] : 0) + (i > 0 && j > 0 ? b[i - 1][j - 1] : 0);
            }
        }
        int ans = 0;
        
    }
    return 0;
}