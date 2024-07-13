// 题解一
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main()
// {
//     int n, q; // n头奶牛，q组查询
//     cin >> n >> q;
//     vector<int> cow(n + 1);
//     vector<int> ans(q);

//     for (int i = 1; i <= n; i++)
//         cin >> cow[i];

//     for (int i = 0; i < q; i++)
//     {
//         int a, b; // 从a到b的奶牛范围
//         cin >> a >> b;

//         vector<int> temp(cow.begin() + a, cow.begin() + b + 1);
//         sort(temp.begin(), temp.end());

//         ans[i] = temp.back() - temp.front();
//     }

//     for (int i = 0; i < q; i++)
//         cout << ans[i] << endl;

//     return 0;
// }

// 题解二
// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <climits>
// using namespace std;

// int main()
// {
//     int n, q; // n头奶牛，q组查询
//     cin >> n >> q;
//     int ans[q];

//     vector<int> cow(n + 1);
//     for (int i = 1; i <= n; ++i)
//         cin >> cow[i];

//     int blockSize = sqrt(n);                         // 每个块的大小
//     int numBlocks = (n + blockSize - 1) / blockSize; // 块的数量

//     vector<int> blockMin(numBlocks, INT_MAX);
//     vector<int> blockMax(numBlocks, INT_MIN);

//     for (int i = 1; i <= n; ++i)
//     {
//         int blockIdx = (i - 1) / blockSize;
//         blockMin[blockIdx] = min(blockMin[blockIdx], cow[i]);
//         blockMax[blockIdx] = max(blockMax[blockIdx], cow[i]);
//     }

//     for (int i = 0; i < q; i++)
//     {
//         int a, b;
//         cin >> a >> b;

//         int minVal = INT_MAX;
//         int maxVal = INT_MIN;

//         int startBlock = (a - 1) / blockSize;
//         int endBlock = (b - 1) / blockSize;

//         if (startBlock == endBlock)
//         {
//             for (int i = a; i <= b; ++i)
//             {
//                 minVal = min(minVal, cow[i]);
//                 maxVal = max(maxVal, cow[i]);
//             }
//         }
//         else
//         {
//             for (int i = a; i <= (startBlock + 1) * blockSize; ++i)
//             {
//                 minVal = min(minVal, cow[i]);
//                 maxVal = max(maxVal, cow[i]);
//             }
//             for (int i = startBlock + 1; i < endBlock; ++i)
//             {
//                 minVal = min(minVal, blockMin[i]);
//                 maxVal = max(maxVal, blockMax[i]);
//             }
//             for (int i = endBlock * blockSize + 1; i <= b; ++i)
//             {
//                 minVal = min(minVal, cow[i]);
//                 maxVal = max(maxVal, cow[i]);
//             }
//         }

//         ans[i] = maxVal - minVal;
//     }
//     for (int i = 0; i < q; i++)
//         cout << ans[i] << endl;

//     return 0;
// }
