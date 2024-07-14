/**
 * 题目大意：

有一个长度为 n 的序列 c_i。现在给出 m 个询问，每次给出两个数 l,r，从编号在 l 到 r 之间的数中随机选出两个不同的数，求两个数相等的概率。
 */
/**
 * 过程
思路：莫队算法模板题。

对于区间 [l,r]，以 l 所在块的编号为第一关键字，r 为第二关键字从小到大排序。

然后从序列的第一个询问开始计算答案，第一个询问通过直接暴力算出，复杂度为 O(n)，后面的询问在前一个询问的基础上得到答案。
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int N = 50005;        // N 是最大可能的序列长度。
int n, m, maxn;             // n 和 m 分 别是序列长度和查询数量，maxn 是莫队算法中块的大小。
int c[N];                   // c 是输入的序列。
long long sum;              // sum 用于记录当前区间内相同数的对数。
int cnt[N];                 // cnt用于记录每个数在当前区间内的出现次数。
long long ans1[N], ans2[N]; // ans1 和 ans2 分别用于存储每个查询的结果的分子和分母。

struct query // query 结构体表示一个查询，包含左端点 l、右端点 r 和查询的编号 id。重载了 < 运算符用于排序。
{
    int l, r, id;
    bool operator<(const query &x) const
    {
        if (l / maxn != x.l / maxn)
            return l < x.l;
        return (l / maxn) & 1 ? r < x.r : r > x.r;
    }
} a[N];

void add(int i) // 将元素 i 添加到当前区间，并更新 sum 和 cnt。
{
    sum += cnt[i];
    cnt[i]++;
}

void del(int i) // 将元素 i 从当前区间删除，并更新 sum 和 cnt。
{
    cnt[i]--;
    sum -= cnt[i];
}

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    scanf("%d%d", &n, &m);
    maxn = sqrt(n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (int i = 0; i < m; i++)
        scanf("%d%d", &a[i].l, &a[i].r), a[i].id = i;
    sort(a, a + m);
    for (int i = 0, l = 1, r = 0; i < m; i++)
    {
        if (a[i].l == a[i].r)
        {
            ans1[a[i].id] = 0, ans2[a[i].id] = 1;
            continue;
        }
        while (l > a[i].l)
            add(c[--l]);

        while (r < a[i].r)
            add(c[++r]);

        while (l < a[i].l)
            del(c[l++]);

        while (r > a[i].r)
            del(c[r--]);
        ans1[a[i].id] = sum;
        ans2[a[i].id] = (long long)(r - l + 1) * (r - l) / 2;
    }
    for (int i = 0; i < m; i++)
    {
        if (ans1[i] != 0)
        {
            long long g = gcd(ans1[i], ans2[i]);
            ans1[i] /= g, ans2[i] /= g;
        }
        else
            ans2[i] = 1;
        printf("%lld/%lld\n", ans1[i], ans2[i]);
    }
    return 0;
}