#include <stdio.h>
#include <string.h>
#include <algorithm>
typedef long long ll;
using namespace std;
int a[50010];
struct node
{
    int l, r, low, high;
} tree[200010];

int high, low;

void build(int l, int r, int p)
{
    tree[p].l = l;
    tree[p].r = r;
    if (l == r)
    {
        tree[p].low = a[l];
        tree[p].high = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * p);
    build(mid + 1, r, 2 * p + 1);
    tree[p].low = min(tree[2 * p].low, tree[2 * p + 1].low);
    tree[p].high = max(tree[2 * p].high, tree[2 * p + 1].high);
}
void qe(int l, int r, int p)
{
    if (tree[p].l == l && tree[p].r == r)
    {
        low = min(low, tree[p].low);
        high = max(high, tree[p].high);
        return;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    if (r <= mid)
        qe(l, r, 2 * p);
    else if (l >= mid + 1)
        qe(l, r, 2 * p + 1);
    else
    {
        qe(l, mid, 2 * p);
        qe(mid + 1, r, 2 * p + 1);
    }
}
int main()
{
    int m, n, x, y;
    while (~scanf("%d%d", &m, &n))
    {
        for (int i = 1; i <= m; i++)
            scanf("%d", &a[i]);
        build(1, m, 1);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &x, &y);
            low = 1100000;
            high = 0;
            qe(x, y, 1);
            printf("%d\n", high - low);
        }
    }
    return 0;
}
