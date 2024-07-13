// #include <iostream>
// #include <vector>
// using namespace std;

// vector<long long> segTree, lazy;
// int n;

// void buildTree(const vector<int> &arr, int l, int r, int pos) // 递归建树
// {
//     if (l == r)
//     {
//         segTree[pos] = arr[l];
//     }
//     else
//     {
//         int mid = (l + r) / 2;
//         buildTree(arr, l, mid, 2 * pos + 1);
//         buildTree(arr, mid + 1, r, 2 * pos + 2);
//         segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
//     }
// }

// void updateRangeUtil(int start, int end, int l, int r, int val, int pos) // 更新区间
// {
//     if (lazy[pos] != 0)
//     {
//         segTree[pos] += (end - start + 1) * lazy[pos];
//         if (start != end)
//         {
//             lazy[2 * pos + 1] += lazy[pos];
//             lazy[2 * pos + 2] += lazy[pos];
//         }
//         lazy[pos] = 0;
//     }

//     if (start > end || start > r || end < l)
//     {
//         return;
//     }

//     if (start >= l && end <= r)
//     {
//         segTree[pos] += (end - start + 1) * val;
//         if (start != end)
//         {
//             lazy[2 * pos + 1] += val;
//             lazy[2 * pos + 2] += val;
//         }
//         return;
//     }

//     int mid = (start + end) / 2;
//     updateRangeUtil(start, mid, l, r, val, 2 * pos + 1);
//     updateRangeUtil(mid + 1, end, l, r, val, 2 * pos + 2);
//     segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
// }

// long long queryRangeUtil(int start, int end, int l, int r, int pos) // 查询区间,求和
// {
//     if (lazy[pos] != 0)
//     {
//         segTree[pos] += (end - start + 1) * lazy[pos];
//         if (start != end)
//         {
//             lazy[2 * pos + 1] += lazy[pos];
//             lazy[2 * pos + 2] += lazy[pos];
//         }
//         lazy[pos] = 0;
//     }

//     if (start > end || start > r || end < l)
//         return 0;

//     if (start >= l && end <= r)
//         return segTree[pos];

//     int mid = (start + end) / 2;
//     return queryRangeUtil(start, mid, l, r, 2 * pos + 1) +
//            queryRangeUtil(mid + 1, end, l, r, 2 * pos + 2);
// }

// void updateRange(int l, int r, int val)
// {
//     updateRangeUtil(0, n - 1, l, r, val, 0);
// }

// long long queryRange(int l, int r)
// {
//     return queryRangeUtil(0, n - 1, l, r, 0);
// }

// int main()
// {
//     int N, Q; // N数组大小，Q查询次数
//     cin >> N >> Q;
//     n = N;

//     vector<int> initial_values(N);
//     for (int i = 0; i < N; ++i)
//         cin >> initial_values[i];

//     segTree.resize(4 * N, 0);
//     lazy.resize(4 * N, 0);

//     buildTree(initial_values, 0, N - 1, 0);

//     vector<long long> results;
//     for (int i = 0; i < Q; ++i)
//     {
//         char type;
//         int a, b, c;
//         cin >> type >> a >> b;
//         if (type == 'C')
//         {
//             cin >> c;
//             updateRange(a - 1, b - 1, c);
//         }
//         else if (type == 'Q')
//             results.push_back(queryRange(a - 1, b - 1));
//     }

//     for (vector<long long>::iterator it = results.begin(); it != results.end(); ++it)
//         cout << *it << "\n";

//     return 0;
// }
#include <iostream>
#include <cstdio>
#define rep(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
const int N = 1E5 + 10;
int w[N];
struct node
{
    int l, r;
    ll val;
    ll lazy;
} t[N << 2];
void pushdown(node &op, ll lazy)
{
    op.val += lazy * (op.r - op.l + 1);
    op.lazy += lazy;
}
void pushdown(int x)
{
    if (!t[x].lazy)
        return;
    pushdown(t[x << 1], t[x].lazy), pushdown(t[x << 1 | 1], t[x].lazy);
    t[x].lazy = 0;
}

void pushup(int x)
{
    t[x].val = t[x << 1].val + t[x << 1 | 1].val;
}

void build(int l, int r, int x = 1)
{
    t[x] = {l, r, w[l], 0};
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(l, mid, x << 1), build(mid + 1, r, x << 1 | 1);
    pushup(x);
}

void modify(int l, int r, int c, int x = 1)
{
    if (l <= t[x].l && r >= t[x].r)
    {
        pushdown(t[x], c);
        return;
    }
    pushdown(x);
    int mid = t[x].l + t[x].r >> 1;
    if (l <= mid)
        modify(l, r, c, x << 1);
    if (r > mid)
        modify(l, r, c, x << 1 | 1);
    pushup(x);
}

ll ask(int l, int r, int x = 1)
{
    if (l <= t[x].l && r >= t[x].r)
        return t[x].val;
    pushdown(x);
    int mid = t[x].l + t[x].r >> 1;
    ll res = 0;
    if (l <= mid)
        res += ask(l, r, x << 1);
    if (r > mid)
        res += ask(l, r, x << 1 | 1);
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    rep(i, n) scanf("%d", &w[i]);
    build(1, n);

    while (m--)
    {
        char op[2];
        int l, r;
        scanf("%s %d %d", op, &l, &r);

        if (*op == 'Q')
            printf("%lld\n", ask(l, r));
        else
        {
            int c;
            scanf("%d", &c);
            modify(l, r, c);
        }
    }
    return 0;
}
