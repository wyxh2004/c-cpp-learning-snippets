#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, i, h, r; // n头奶牛，最高奶牛的索引，最高奶牛的高度，r行信息
void fun(int i, int j, vector<int> &cow, vector<int> &kdl)
{
    int left = min(i, j);
    int right = max(i, j);
    int index = left * n + right; // 计算索引
    if (kdl[index] == 1)
        return; // 去重
    kdl[index] = 1;
    for (int m = left + 1; m < right; ++m)
        cow[m]--;
}
int main()
{

    cin >> n >> i >> h >> r;
    vector<int> cow(n, h);
    vector<int> kdl(n * n, 0); // 用于去重
    cow[i - 1] = h;
    while (r--)
    {
        // r行信息
        int a, b;
        cin >> a >> b;
        fun(a - 1, b - 1, cow, kdl);
    }
    for (unsigned int x = 0; x < n; x++)
        cout << cow[x] << endl;

    return 0;
}