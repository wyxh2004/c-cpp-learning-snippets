// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n, q, c; // 星星的数量、视图的数量和星星的最大亮度
//     cin >> n >> q >> c;
//     while (n--)
//     {
//         int xi, yi, si; // 第i颗恒星的坐标及其初始亮度。
//         cin >> xi >> yi >> si;
//     }
//     while (q--)
//     {
//         int ti, x1i, y1i, x2i, y2i;
//         cin >> ti >> x1i >> y1i >> x2i >> y2i;
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int arr[11][101][101]; // each max brightness, each mod,

int query(int cur, int x1, int x2, int y1, int y2)
{
    return arr[cur][x2][y2] - arr[cur][x1 - 1][y2] - arr[cur][x2][y1 - 1] + arr[cur][x1 - 1][y1 - 1];
}

int main()
{
    int n, q, c;
    cin >> n >> q >> c;
    for (int i = 0; i < n; ++i)
    {
        int x, y, s;
        cin >> x >> y >> s;
        for (int j = 0; j < c + 1; ++j)
            arr[j][x][y] += ((s + j) % (c + 1));
    }

    for (int i = 0; i < 11; ++i)
        for (int j = 1; j < 101; ++j)
            for (int k = 1; k < 101; ++k)
            {
                arr[i][j][k] += (arr[i][j - 1][k] + arr[i][j][k - 1] - arr[i][j - 1][k - 1]);
            }

    for (int i = 0; i < q; ++i)
    {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        cout << query(t % (c + 1), x1, x2, y1, y2) << "\n";
    }
}