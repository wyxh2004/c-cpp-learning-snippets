#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 读取礼物的数量
    int n;
    cin >> n;
    vector<int> prices(n);

    // 读取每个礼物的价格
    for (int i = 0; i < n; ++i)
    {
        cin >> prices[i];
    }

    // 价格排序
    sort(prices.begin(), prices.end());

    // 构建前缀和数组
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        prefixSum[i] = prefixSum[i - 1] + prices[i - 1];
    }

    // 读取查询的数量
    int Q;
    cin >> Q;
    vector<pair<int, int>> queries(Q);

    // 读取所有查询区间
    for (int i = 0; i < Q; ++i)
    {
        cin >> queries[i].first >> queries[i].second;
    }

    // 处理每个查询并存储结果
    vector<long long> results(Q);
    for (int i = 0; i < Q; ++i)
    {
        int a = queries[i].first;
        int b = queries[i].second;

        // 使用二分查找确定范围
        int left = lower_bound(prices.begin(), prices.end(), a) - prices.begin();
        int right = upper_bound(prices.begin(), prices.end(), b) - prices.begin() - 1;

        // 计算总价格
        long long sum = 0;
        if (left <= right)
        {
            sum = prefixSum[right + 1] - prefixSum[left];
        }

        // 存储结果
        results[i] = sum;
    }

    // 一次性输出所有结果
    for (int i = 0; i < Q; ++i)
    {
        cout << results[i] << endl;
    }

    return 0;
}
