// #include <iostream>
// using namespace std;

// int main()
// {
//     int T;          // T组测试数据
//     int m, n, x, y; // m*n的整数矩阵，x*y的子矩阵
//     int arr[1000][1000];
//     int partial_sum[1000][1000];

//     cin >> T;
//     int max = 0;
//     while (T--)
//     {

//         cin >> m >> n >> x >> y;
//         for (unsigned int i = 0; i < m; i++)
//         {
//             for (unsigned j = 0; j < n; j++)
//             {
//                 cin >> arr[i][j];
//             }
//         }
//         partial_sum[0][0] = arr[0][0];
//         for (unsigned int i = 1; i < x; i++)
//         {
//             for (unsigned int j = 1; j < y; j++)
//             {
//                 partial_sum[i][j] = partial_sum[i - 1][j] + partial_sum[i][j - 1] - partial_sum[i - 1][j - 1] + arr[i][j];
//                 if (partial_sum[i][j] > max)
//                     max = partial_sum[i][j];
//             }
//         }
//     }
//     cout << max << endl;
//     return 0;
// }
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int T; // T组测试数据
    cin >> T;

    while (T--)
    {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        vector<vector<int>> arr(m, vector<int>(n));
        vector<vector<int>> partial_sum(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> arr[i][j];
            }
        }

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                partial_sum[i][j] = arr[i - 1][j - 1] + partial_sum[i - 1][j] + partial_sum[i][j - 1] - partial_sum[i - 1][j - 1];
            }
        }

        int max_sum = 0;

        // 找到最大的 x*y 子矩阵和
        for (int i = x; i <= m; ++i)
        {
            for (int j = y; j <= n; ++j)
            {
                int sub_sum = partial_sum[i][j] - partial_sum[i - x][j] - partial_sum[i][j - y] + partial_sum[i - x][j - y];
                max_sum = max(max_sum, sub_sum);
            }
        }

        cout << max_sum << endl;
    }

    return 0;
}
