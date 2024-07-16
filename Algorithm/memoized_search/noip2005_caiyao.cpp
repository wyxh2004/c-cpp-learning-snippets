/**
 * 山洞里有 M 株不同的草药，采每一株都需要一些时间 t_i，每一株也有它自身的价值 v_i。给你一段时间 T，在这段时间里，你可以采到一些草药。让采到的草药的总价值最大。
 */

// 朴素的dfs做法
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int t, m;                  // 时间和草药数量
int tcost[103], mget[103]; // 每株草药需要的时间,草药的价值
int ans = 0;               // 最终答案

void dfs(int pos, int tleft, int tans) // 当前准备选第几个物品、剩余的时间是多少、已经获得的价值是多少
{
    if (tleft < 0)
        return;
    if (pos == m + 1) // 当前已经选完了
    {
        ans += max(ans, tans);
        return;
    }
    dfs(pos + 1, tleft, tans);                          // 不选当前物品
    dfs(pos + 1, tleft - tcost[pos], tans + mget[pos]); // 选当前物品
}

int main()
{
    cin >> t >> m;

    for (int i = 1; i <= m; i++)
        cin >> tcost[i] >> mget[i];
    dfs(1, t, 0);
    cout << ans;
    return 0;
}