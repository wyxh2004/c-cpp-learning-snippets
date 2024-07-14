莫队算法是由莫涛提出的算法。在莫涛提出莫队算法之前，莫队算法已经在 Codeforces 的高手圈里小范围流传，但是莫涛是第一个对莫队算法进行详细归纳总结的人。莫涛提出莫队算法时，只分析了普通莫队算法，但是经过 OIer 和 ACMer 的集体智慧改造，莫队有了多种扩展版本。

莫队算法可以解决一类离线区间询问问题，适用性极为广泛。同时将其加以扩展，便能轻松处理树上路径询问以及支持修改操作。

```c
int l = 0, r = 0, nowAns = 0;

inline void move(int pos, int sign) {
    // update nowAnswer
}

void solve() {
    BLOCK_SIZE = int(ceil(pow(n, 0.5)));
      sort(querys, querys + m);
    for (int i = 0; i < m; ++i) {
        const query &q = querys[i];
        while (l > q.l) move(--l, 1);
        while (r < q.r) move(r++, 1);
        while (l < q.l) move(l++, -1);
        while (r > q.r) move(--r, -1);
        ans[q.id] = nowAns;
    }
}
```

对n个数进行分块，再对原询问进行如下排序
```c
int block_size = sqrt(n);

bool operator<(const Query &sec) const
{
    if(l/block_size != sec.l/block_size) return l < sec.l;
    else return r < sec.r;
}
```
对左端进行按块分区，区号越小越靠前，同区就看右端，右端越小越靠前