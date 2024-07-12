#include <iostream>
#include <cstring>
using namespace std;

int n, k;
int rect[1001][1001]; // 原点到点(i,j)围成的矩形的总和int main()

int main()
{

    cin >> n >> k;
    while (n--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 初始化矩形
        rect[x1 + 1][y1 + 1]++;
        rect[x2 + 1][y2 + 1]++;
        rect[x1 + 1][y2 + 1]--;
        rect[x2 + 1][y1 + 1]--;
    }
    int ans = 0;
    for (unsigned int i = 1; i <= 1000; i++)
    {
        for (unsigned int j = 1; j <= 1000; j++)
        {
            rect[i][j] += rect[i - 1][j] + rect[i][j - 1] - rect[i - 1][j - 1];
            if (rect[i][j] == k)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}