#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define N 100000
using namespace std;

int n, L, R, ans, m;

struct node
{
    int l, r;
    bool cv; // 区间覆盖
};

node Tree[N];

void build(int i, int l, int r) // i为当前节点，l,r为当前节点表示的区间
{
    int mid = (l + r) / 2;
    Tree[i].l = l;
    Tree[i].r = r;
    Tree[i].cv = 0; // 线段树的域
    if (l == r)     // 无法再分
        return;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
}

void insert(int i, int l, int r) // i为当前节点，l,r为当前节点表示的区间
{
    if (r < Tree[i].l || l > Tree[i].r)
        return;
    if (l < Tree[i].l && r > Tree[i].r)
    {
        Tree[i].cv = 1;
        return;
    }
    insert(2 * i, l, r);
    insert(2 * i + 1, l, r);
}

int sum(int i)
{
    if (Tree[i].cv == 1)
        return Tree[i].r - Tree[i].l + 1;
    else
    {
        if (Tree[i].l == Tree[i].r)
            return 0;
        else
            return sum(i * 2) + sum(i * 2 + 1); // 两个孩子之和
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> L >> R >> n;
    if (L < 0)
        m = -L;
    L += m;
    R += m;
    build(1, L, R - 1);
    for (int i = 1; i <= n; i++)
    {
        int ll, rr;
        cin >> ll >> rr;
        ll += m;
        rr += m;
        insert(1, ll, rr - 1);
    }
    ans = sum(1);
    cout << ans;
    return 0;
}