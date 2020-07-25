#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
const int N = 2e6 + 5;
const ll MOD = 1e9+7;
unordered_map<ll, int> mp;
ll f[N];

void init()
{
    f[0] = f[1] = 1;
    mp[f[1]] = 1;
    for (int i = 2; i < N; ++i) {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
        if(mp.count(f[i])) puts("error");
        mp[f[i]] = i;
    }
}

inline ll mult(ll a, ll b)
{
    ll ret = 0;
    while (b) {
        if (b & 1)
            ret = (ret + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return ret;
}

inline int read()
{
    int x = 0, s = 1, ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            s = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * s;
}

int main()
{
    init();
    int t;
    while (~scanf("%d", &t)) {
        while (t--) {
            ll a[3], k;
            for (int i = 0; i < 3; ++i) {
                k = read(), a[i] = 0;
                for (int j = 1; j <= (int)k; ++j)
                    a[i] = (a[i] + read() * f[j]) % MOD;
            }
            ll res = (mult(a[0], a[1]) - a[2]) % MOD;
            res = (res + MOD) % MOD;
            printf("%d\n", mp[res]);
        }
    }
    return 0;
}
