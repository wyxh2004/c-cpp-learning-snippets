#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int d[m];

void build(int s, int t, int p)
{
    // 对 [s,t] 区间建立线段树,当前根的编号为 p
    if (s == t)
    {
        d[p] = a[s];
        return;
    }
    int m = s + ((t - s) >> 1);
    // 移位运算符的优先级小于加减法，所以加上括号
    // 如果写成 (s + t) >> 1 可能会超出 int 范围
    build(s, m, p * 2), build(m + 1, t, p * 2 + 1);
    // 递归对左右区间建树
    d[p] = d[p * 2] + d[(p * 2) + 1];
}

int getsum(int l, int r, int s, int t, int p) {}

int main()
{

    return 0;
}