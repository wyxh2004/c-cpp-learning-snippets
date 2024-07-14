// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <algorithm>
// #include <cstdio>

// using namespace std;

// int block_size, num_block; // 块的大小, 块的数量
// vector<string> block;

// void initialize(const string s)
// {
//     int size = s.size();
//     block_size = sqrt(size);
//     num_block = (size + block_size - 1) / block_size;
//     block.resize(num_block);
//     for (int i = 0; i < size; i++)
//         block[i / block_size].push_back(s[i]); // 在block末尾插入字符
// }

// void insert(char ch, int index)
// {
//     int block_index = index / block_size;
//     int positoin = index % block_size;
//     if (index >= block.size())
//     {
//         if (block.empty())
//             block.push_back(string(1, ch));
//         block.back().push_back(ch);
//     }
//     else
//     {
//         block[block_index].insert(block[block_index].begin() + positoin, ch);
//         // 在一个块中插入字符后，可能会导致该块的大小超过预设的 BLOCK_SIZE。为了保持每个块的大小在合理范围内，需要将多余的字符移动到相邻的块中。
//         for (int i = block_index; i < block.size(); i++)
//         {
//             if (block[i].size() > block_size) // 块的大小超过预设的 BLOCK_SIZE
//             {
//                 if (i == block.size() - 1) // 最后一个块
//                 {
//                     block.push_back(string(1, block[i].back()));
//                     block[i].pop_back();
//                 }
//                 else
//                 {
//                     block[i + 1].push_back(block[i].back());
//                     block[i].pop_back();
//                 }
//             }
//         }
//     }
// }

// char query(int index)
// {
//     int block_index = index / block_size;
//     int position = index % block_size;
//     return block[block_index][position];
// }

// int main()
// {
//     string str; // 初始字符串
//     cin >> str;
//     int n;
//     cin >> n; // 操作的数量
//     initialize(str);
//     vector<char> answers;

//     while (n--)
//     {
//         char opt;    // Query or Insert
//         char letter; // 插入的字符
//         int query_num, insert_num;
//         cin >> opt;

//         if (opt == 'Q') // Query
//         {
//             cin >> query_num;
//             answers.push_back(query(query_num));
//         }
//         else if (opt == 'I')
//         {
//             cin >> letter >> insert_num;
//             insert(letter, insert_num);
//         }
//     }

//     for (char ans : answers)
//         cout << ans << endl;

//     return 0;
// }

#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1000010
#define MAXM 1001
using namespace std;
int n, m, k, ans, tot, len[MAXN];
char s[MAXM][MAXM * 10], ch[3], ss[MAXN];
void add(char c, int x)
{
    int l1 = 0, p = n;
    for (int i = 1; i <= n; i++)
    {
        if (l1 + len[i] >= x || i == n)
        {
            p = i;
            break;
        }
        l1 += len[i];
    }
    int pos = x - l1;
    len[p] = max(pos, len[p] + 1);
    for (int i = len[p]; i > pos; i--)
        s[p][i] = s[p][i - 1];
    s[p][pos] = c;
    return;
}
char query(int x)
{
    int l1 = 0, p = n;
    for (int i = 1; i <= n; i++)
    {
        if (l1 + len[i] >= x)
        {
            p = i;
            break;
        }
        l1 += len[i];
    }
    return s[p][x - l1];
}
void slove()
{
    memset(len, 0, sizeof len);
    memset(s, 0, sizeof s);
    scanf("%d", &k);
    int l = strlen(ss), x = (l + 999) / 1000;
    n = (l - 1) / x + 1;
    for (int i = 0; i < l; i++)
        s[i / x + 1][i % x + 1] = ss[i], len[i / x + 1]++;
    while (k--)
    {
        scanf("%s", ch);
        if (ch[0] == 'Q')
            scanf("%d", &x), printf("%c\n", query(x));
        else
            scanf("%s%d", ch, &x), add(ch[0], x);
    }
}
int main()
{
    while (~scanf("%s", ss))
        slove();
}