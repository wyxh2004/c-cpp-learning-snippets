#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define maxn 1000010
int n, m, a[maxn], cnt[maxn], ans[maxn], bein[maxn], l = 1, r, now;

struct node
{
    int l, r, id; // 左右端点，序号
} q[maxn];

bool cmp(node a, node b)
{
    return bein[a.l] == bein[b.l] ? a.r < b.r : bein[a.l] < bein[b.l];
}

void add(int x) // 加入操作 （右移
{
    if (cnt[a[x]] == 0)
        ++now;
    ++cnt[a[x]];
}

void del(int x) // 删除（左移
{
    --cnt[a[x]];
    if (cnt[a[x]] == 0)
        --now;
}

void print(int x) // 递归输出
{
    if (x / 10)
        print(x / 10);
    putchar(x % 10 + '0');
}

int main()
{
    scanf("%d", &n); // n个数
    for (int i = 1; i <= ceil((double)n / sqrt(n)); ++i)
        for (int j = (i - 1) * sqrt(n) + 1; j <= i * sqrt(n); ++j)
            bein[j] = i; // 分的块
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &q[i].l, &q[i].r); // 还要输入
        q[i].id = i;                     // 记录下序号，cmp中要用
    }
    sort(q + 1, q + m + 1, cmp); // 排序

    for (int i = 1; i <= m; ++i)
    {
        while (l < q[i].l) // l右移
            del(l++);
        while (l > q[i].l) // l左移
            add(--l);
        while (r < q[i].r) // r右移
            add(++r);
        while (r > q[i].r) // r左移
            del(r--);
        ans[q[i].id] = now;
    }
    for (int i = 1; i <= m; ++i)
    {
        print(ans[i]); // 输出
        printf("\n");  // 记得换行
    }
    return 0;
}