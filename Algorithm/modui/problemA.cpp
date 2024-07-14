// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <algorithm>
// #include <unordered_set>
// using namespace std;

// struct query
// {
//     int l, r, idx;
// };

// // 检查区间[L,R]中是否所有元素都互不相同
// bool check(vector<int> &arr, int L, int R)
// {
//     unordered_set<int> elements;
//     for (int i = L; i <= R; ++i)
//     {
//         if (elements.find(arr[i]) != elements.end())
//         {
//             return false;
//         }
//         elements.insert(arr[i]);
//     }
//     return true;
// }

// int main()
// {
//     int N, Q;
//     cin >> N >> Q;    // N个整数，Q个查询
//     vector<int> A(N); // 存储数组A
//     for (int i = 0; i < N; ++i)
//         cin >> A[i];
//     vector<query> queries(Q); // 存储查询
//     for (int i = 0; i < Q; i++)
//     {
//         cin >> queries[i].l >> queries[i].r;
//         queries[i].l--; // 转换为0索引
//         queries[i].r--; // 转换为0索引
//         queries[i].idx = i;
//     }
//     int blockSize = sqrt(N); // 块大小
//     sort(queries.begin(), queries.end(),
//          [blockSize](const query &a, const query &b)
//          {
//              if (a.l / blockSize != b.l / blockSize)
//              {
//                  return a.l / blockSize < b.l / blockSize;
//              }
//              return a.r < b.r;
//          });
//     vector<string> results(Q);
//     int currentL = 0, currentR = -1;
//     unordered_set<int> currentElements; // 存储当前区间内的元素，使用unordered_set是因为需要快速查找和删除

//     for (const auto &q : queries)
//     {
//         while (currentL < q.r) // 当前左边界小于查询右边界
//         {
//             currentL++;
//             currentElements.insert(A[currentL]);
//         }
//         while (currentR > q.r) // 当前右边界大于查询右边界
//         {
//             currentElements.erase(A[currentR]);
//             currentR--;
//         }
//         while (currentL < q.l) // 当前左边界小于查询左边界
//         {
//             currentElements.erase(A[currentL]);
//             currentL++;
//         }
//         while (currentR < q.l) // 当前右边界小于查询左边界
//         {
//             currentElements.erase(A[currentR]);
//             currentR++;
//         }
//         results[q.idx] = (currentElements.size() == q.r - q.l + 1) ? "Yes" : "No";
//     }
//     for (const auto &i : results)
//         cout << i << endl;

//     return 0;
// }
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 100010;

int n, m, bl, answer = 0, curL, curR, cnt[maxn], a[maxn]; // n个数，m个询问，bl为块大小，answer为当前区间内不同数的个数，curL和curR为当前区间的左右端点，cnt为每个数出现的次数，a为原数组
bool ans[maxn];

struct Query
{
    int l, r, p;
} q[maxn];

bool cmp(const Query &a, const Query &b)
{
    return (a.l / bl) == (b.l / bl) ? a.r < b.r : a.l < b.l;
}
void add(int pos)
{
    if ((++cnt[a[pos]]) == 1)
        ++answer;
}
void del(int pos)
{
    if ((--cnt[a[pos]]) == 0)
        --answer;
}
int main()
{
    cin >> n >> m;
    bl = sqrt(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= m; i++)
    {
        cin >> q[i].l;
        cin >> q[i].r;
        q[i].p = i;
    }

    sort(q + 1, q + 1 + m, cmp);

    for (int i = 1; i <= m; i++)
    {
        int L = q[i].l, R = q[i].r;
        while (curL < L)
            del(curL++);
        while (curL > L)
            add(--curL);
        while (curR < R)
            add(++curR);
        while (curR > R)
            del(curR--);
        if (answer == (R - L + 1))
            ans[q[i].p] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        if (ans[i] == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
