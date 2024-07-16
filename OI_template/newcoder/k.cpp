/**
 * 给定一个简单的无向连通图 G（其中边数等于顶点数）和一棵无根树 H，确定是否可以通过从 G 中删除顶点或边并重新标记顶点来生成 H。
输入描述：
第一行包含一个整数T (1≤T≤1 000)T(1≤T≤1000)，表示测试用例的数量。
对于每个测试用例：
第一行包含一个整数n (3≤n≤1 000)n(3≤n≤1000)，表示图GG的顶点数和边数。
接下来的 n 行每行包含两个整数 u,v (1≤u,v≤n)u,v(1≤u,v≤n)，表示图 G 的边。保证图GG不包含自环或重边。
接下来一行包含一个整数m (1≤m≤n)m(1≤m≤n)，表示树H的顶点数。
接下来的 m−1 行每行包含两个整数 u,v (1≤u,v≤m)u,v(1≤u,v≤m)，表示树 HH 的边。
保证所有测试用例中n的总和不超过1000。
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> ans(t);
int t;                          // 样例数量
vector<vector<int>> G(t), T(t); // G是图，T是树
vector<string> ans(t);

bool is_subgraph(vector<vector<int>> G, vector<vector<int>> T)
{
    // 判断T是否是G的子图
    for (int i = 0; i < T.size(); i++)
    {
        for (int j = 0; j < T[i].size(); j++)
        {
            if (find(G[i].begin(), G[i].end(), T[i][j]) == G[i].end())
                return false;
        }
    }
    return true;
}

int main()
{
    cin >> t; // 样例数量
    for (int i = 0; i < t; i++)
    {
        int n; // G的顶点和边
        cin >> n;
        build_tree(T, n, G_edges);
        int m; // H的顶点和边
        cin >> m;
        build_tree(G, m, T_edges);
    }

    for (int i = 0; i < t; i++)
    {
        if (is_subgraph(G, T))
            ans[i] = "Yes";

        else
            ans[i] = "No";
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << endl;

    return 0;
}