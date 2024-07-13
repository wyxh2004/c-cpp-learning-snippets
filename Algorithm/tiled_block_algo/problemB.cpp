#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> arr, block, lazy; // 原始数组，块数组和懒惰数组
int block_size, num_blocks;         // 块大小和块数

void initialize(const vector<int> &data)
{
    int n = data.size();
    block_size = sqrt(n);
    num_blocks = (n + block_size - 1) / block_size;

    arr.resize(n);
    block.resize(num_blocks);
    lazy.resize(num_blocks, 0);

    for (int i = 0; i < n; ++i)
    {
        arr[i] = data[i];
        block[i / block_size] += data[i];
    }
}

void update_range(int l, int r, int val)
{
    int start_block = l / block_size;
    int end_block = r / block_size;

    if (start_block == end_block) // 在同一个块内
    {
        for (int i = l; i <= r; ++i)
        {
            arr[i] += val;
            block[start_block] += val;
        }
    }
    else
    {
        for (int i = l; i < (start_block + 1) * block_size; ++i)
        {
            arr[i] += val;
            block[start_block] += val;
        }
        for (int i = start_block + 1; i < end_block; ++i)
        {
            lazy[i] += val;
        }
        for (int i = end_block * block_size; i <= r; ++i)
        {
            arr[i] += val;
            block[end_block] += val;
        }
    }
}

long long query_range(int l, int r)
{
    int start_block = l / block_size;
    int end_block = r / block_size;
    long long sum = 0;

    if (start_block == end_block)
    {
        for (int i = l; i <= r; ++i)
        {
            sum += arr[i] + lazy[start_block];
        }
    }
    else
    {
        for (int i = l; i < (start_block + 1) * block_size; ++i)
        {
            sum += arr[i] + lazy[start_block];
        }
        for (int i = start_block + 1; i < end_block; ++i)
        {
            sum += block[i] + lazy[i] * block_size;
        }
        for (int i = end_block * block_size; i <= r; ++i)
        {
            sum += arr[i] + lazy[end_block];
        }
    }
    return sum;
}
int main()
{
    int N, Q; // N为数组大小，Q为操作数
    cin >> N >> Q;

    vector<int> answer(Q);

    vector<int> initial_values(N);
    for (int i = 0; i < N; ++i)
        cin >> initial_values[i];

    initialize(initial_values);

    for (int i = 0; i < Q; ++i)
    {
        char type;
        int a, b, c;
        cin >> type >> a >> b;
        if (type == 'C')
        {
            cin >> c;
            update_range(a - 1, b - 1, c);
        }
        else if (type == 'Q')
            answer[i] = query_range(a - 1, b - 1);
    }
    for (int i = 0; i < Q; i++)
    {
        if (answer[i] != 0)
            cout << answer[i] << endl;
        continue;
    }
    return 0;
}