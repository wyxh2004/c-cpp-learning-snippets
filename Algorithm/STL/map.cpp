/**
 * hdu 2648 "shopping"
 * 题目大意：输入若干个店家，和n天涨价的价格，输出n天后memory店的价格在所有店里面的排名
使用stl的map使店家的字符串和店内价格创建映射，每次涨价后map的second值便累加，最后输出memory店当前排名

Sample Input                Sample Output
3                           1
memory                      2
kfc
wind
2
49 memory
49 kfc
48 wind
80 kfc
85 wind
83 memory
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, p; // n个店家，天数m，涨价p
    map<string, int> mp;
    while (cin >> n)
    {
        string s;
        for (int i = 0; i < n; i++)
            cin >> s;
        cin >> m;
        while (m--)
        {
            for (int i = 0; i < n; i++)
            {
                cin >> p >> s;
                mp[s] += p;
            }
            int rank = 1;
            map<string, int>::iterator it; // 迭代器
            for (it = mp.begin(); it != mp.end(); it++)
                if (it->second > mp["memory"])
                    rank++;
            cout << rank << endl;
        }
        // 记得清空map
        mp.clear();
    }
    return 0;
}