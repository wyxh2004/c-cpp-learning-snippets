#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long
const int maxn = 1e6 + 10;
int belong[maxn], a[maxn], block;
ll cnt[maxn], ans[maxn], sum;

struct Node
{
    int l, r, id;
    friend bool operator<(const Node &a, const Node &b) // 使用友元函数方便重载运算符
    {
        return belong[a.l] == belong[b.l] ? a.r < b.r : belong[a.l] < belong[b.l];
    }
} q[maxn];

inline void Del(int x)
{ // 计算减去的贡献。
    sum -= cnt[a[x]] * 2 * a[x] - a[x];
    cnt[a[x]]--;
}
inline void Add(int x)
{ // 计算加上的贡献。
    sum += cnt[a[x]] * 2 * a[x] + a[x];
    cnt[a[x]]++;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    block = sqrt(n); // 计算块大小。
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        belong[i] = (i - 1) / block + 1; // 计算每个点属于哪块。
    }
    for (int i = 1; i <= m; ++i)
    { // 把询问离线
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q + 1, q + m + 1);
    int l = 1, r = 0;
    for (int i = 1; i <= m; ++i)
    {
        int ql = q[i].l, qr = q[i].r;
        while (l < ql)
            Del(l++);
        while (l > ql)
            Add(--l);
        while (r < qr)
            Add(++r);
        while (r > qr)
            Del(r--);
        ans[q[i].id] = sum;
    }
    for (int i = 1; i <= m; ++i)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}