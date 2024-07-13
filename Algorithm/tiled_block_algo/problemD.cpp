// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// #define ll long long
// using namespace std;
// vector<ll> arr, block, lazy; // 原始数组，块数组之和，延迟数组
// ll num_blocks, block_size;
// void intialize(vector<ll> &data)
// {
//     ll n = data.size();
//     block_size = sqrt(n);
//     num_blocks = n / block_size + n % block_size;
//     arr.resize(n);
//     block.resize(num_blocks);
//     lazy.resize(num_blocks, 0);
//     for (ll i = 0; i < n; i++)
//     {
//         arr[i] = data[i];
//         block[i / block_size] += arr[i];
//     }
// }

// void update(ll l, ll r, int val)
// {
//     ll left_block = l / block_size;
//     ll right_block = r / block_size;
//     if (left == right)
//     {
//         for (ll i = left_block; i <= right_block; i++)
//         {
//             arr[i] += val;
//             block[left_block] += val;
//         }
//     }
//     else
//     {
//         for (ll i = l; i < (left_block + 1) * block_size; i++)
//         {
//             arr[i] += val;
//             block[left_block] += val;
//         }
//         for (ll i = left_block + 1; i < right_block; i++)
//         {
//             lazy[i] += val;
//         }
//         for (ll i = right_block * block_size; i <= r; i++)
//         {
//             arr[i] += val;
//             block[right_block] += val;
//         }
//     }
// }

// ll query(ll l, ll r)
// {
//     ll left_block = l / block_size;
//     ll right_block = r / block_size;
//     ll sum = 0;
//     if (left_block == right_block)
//     {
//         for (ll i = l; i <= r; i++)
//             sum += arr[i];
//     }
//     else
//     {
//         for (ll i = l; i < (left_block + 1) * block_size; i++)
//         {
//             sum += arr[i];
//         }
//         for (ll i = left_block + 1; i < right_block; i++)
//         {
//             sum += block[i] + lazy[i];
//         }
//         for (ll i = right_block * block_size; i <= r; i++)
//         {
//             sum += arr[i] + lazy[right_block];
//         }
//     }
//     return sum;
// }

// int main()
// {
//     ll n; // n个数字
//     cin >> n;
//     ll opt, l, r, c; // opt(0开方1求和)，区间为[l, r], c暂时没用
//     vector<ll> initial_values;
//     vector<ll> answers;
//     ll count = 0;
//     for (int i = 0; i < n; i++)
//         cin >> initial_values[i];
//     while (n--)
//     {
//         cin >> opt >> l >> r >> c;
//         if (opt == 0)
//             update(l, r, c);
//         else if (opt == 1)
//         {
//             answers.push_back(query(l, r));
//             count++;
//         }
//     }
//     for (ll i = 0; i < count; i++)
//         cout << answers[i] << endl;

//     return 0;
// }
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

#define ll long long
using namespace std;

vector<ll> arr, block, lazy; // 原始数组，块数组之和，延迟数组
ll num_blocks, block_size;

void initialize(const vector<ll> &data)
{
    ll n = data.size();
    block_size = sqrt(n);
    num_blocks = (n + block_size - 1) / block_size; // ceil(n / block_size)
    arr.resize(n);
    block.resize(num_blocks, 0);
    lazy.resize(num_blocks, 0);
    for (ll i = 0; i < n; i++)
    {
        arr[i] = data[i];
        block[i / block_size] += arr[i];
    }
}

void update(ll l, ll r)
{
    ll left_block = l / block_size;
    ll right_block = r / block_size;

    if (left_block == right_block)
    {
        for (ll i = l; i <= r; i++)
        {
            if (arr[i] > 1)
            {
                block[left_block] -= arr[i];
                arr[i] = floor(sqrt(arr[i]));
                block[left_block] += arr[i];
            }
        }
    }
    else
    {
        for (ll i = l; i < (left_block + 1) * block_size; i++)
        {
            if (arr[i] > 1)
            {
                block[left_block] -= arr[i];
                arr[i] = floor(sqrt(arr[i]));
                block[left_block] += arr[i];
            }
        }
        for (ll i = right_block * block_size; i <= r; i++)
        {
            if (arr[i] > 1)
            {
                block[right_block] -= arr[i];
                arr[i] = floor(sqrt(arr[i]));
                block[right_block] += arr[i];
            }
        }
        for (ll i = left_block + 1; i < right_block; i++)
        {
            for (ll j = i * block_size; j < (i + 1) * block_size; j++)
            {
                if (arr[j] > 1)
                {
                    block[i] -= arr[j];
                    arr[j] = floor(sqrt(arr[j]));
                    block[i] += arr[j];
                }
            }
        }
    }
}

ll query(ll l, ll r)
{
    ll left_block = l / block_size;
    ll right_block = r / block_size;
    ll sum = 0;

    if (left_block == right_block)
    {
        for (ll i = l; i <= r; i++)
        {
            sum += arr[i];
        }
    }
    else
    {
        for (ll i = l; i < (left_block + 1) * block_size; i++)
        {
            sum += arr[i];
        }
        for (ll i = left_block + 1; i < right_block; i++)
        {
            sum += block[i];
        }
        for (ll i = right_block * block_size; i <= r; i++)
        {
            sum += arr[i];
        }
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; // n个数字
    scanf("%lld", &n);

    vector<ll> initial_values(n);
    for (ll i = 0; i < n; i++)
        scanf("%lld", &initial_values[i]);

    initialize(initial_values);

    vector<ll> answers;
    while (n--)
    {
        ll opt, l, r, c; // opt(0开方1求和)，区间为[l, r], c暂时没用
        scanf("%lld %lld %lld %lld", &opt, &l, &r, &c);
        l--;
        r--;

        if (opt == 0)
            update(l, r);
        else if (opt == 1)
            answers.push_back(query(l, r));
    }

    for (ll answer : answers)
        printf("%lld\n", answer);

    return 0;
}
