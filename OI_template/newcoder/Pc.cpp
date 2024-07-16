#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 5;
const int mod = 1000000007;
int a[maxn];
int main()
{
    ll q, t, v, tt = 0, ans = 0;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> t >> v;
        while (t-- && tt > 0)
        {
            ans = (ans + mod - (a[tt] * tt) % mod) % mod;
            a[tt] = 0;
            tt--;
        }
        tt++;
        a[tt] = v % mod;
        ans = (ans % mod + (a[tt] * tt) % mod) % mod;
        cout << ans << endl;
    }
    return 0;
}