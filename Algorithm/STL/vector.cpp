/**
 *  hdu4841 “圓桌問題”
 * 圆桌上围坐着2n个人。其中n个人是好人，另外n个人是坏人。如果从第一个人开始数数，数到第m个人，则立即处死该人；然后从被处死的人之后开始数数，再将数到的第m个人处死……依此方法不断处死围坐在圆桌上的人。试问预先应如何安排这些好人与坏人的座位，能使得在处死n个人之后，圆桌上围坐的剩余的n个人全是好人。
 * Input
 * 多组数据，每组数据输入：好人和坏人的人数n（<=32767）、步长m（<=32767）；
 * Output
 * 对于每一组数据，输出2n个大写字母，‘G’表示好人，‘B’表示坏人，50个字母为一行，不允许出现空白字符。相邻数据间留有一空行。
 * ----------
 * 樣例：
 * Input:
 * 2 3
 * 2 4
 * Output:
 * GBBG
 * BGGB
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> table;
    int n, m;

    while (cin >> n >> m)
    {
        table.clear();
        for (int i = 0; i < 2 * n; i++)
            table.push_back(i);     // 初始化
        int pos = 0;                // 記錄初始位置
        for (int i = 0; i < n; i++) // 趕走n個人
        {
            pos = (pos + m - 1) % table.size(); // 圓桌是環，取餘處理
            table.erase(table.begin() + pos);   // 趕走壞人，人數減1
        }
        int j = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            if (!(i % 50) && i)
                cout << endl;
            if (j < table.size() && i == table[j]) // table留下的都是好人
            {
                j++;
                cout << "G";
            }
            else
            {
                cout << "B";
            }
        }
        cout << endl
             << endl; // 留一個空行
    }

    return 0;
}
