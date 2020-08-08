#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 205, MOD = 998244353;

ll g[N][N], p[N][N], d[N];

ll quick_pow(ll a, ll b)
{
    ll ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

void init(int n)
{
    for (int i = 0; i <= n; ++i) {
        d[i] = 0;
        for (int j = 0; j <= n; ++j) {
            g[i][j] = 0;
        }
    }
}

ll det(int n)
{
    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = i; j < n && u == -1; ++j)
            if (p[j][i] != 0)
                u = j;

        if (u == -1)
            return 0;

        if (i != u)
            ans *= -1;
        std::swap(p[i], p[u]);
        ans = (ans * p[i][i]) % MOD;
        auto x = quick_pow(p[i][i], MOD - 2);
        for (int j = i; j < n; ++j)
            p[i][j] = (p[i][j] * x) % MOD;

        for (int j = 0; j < n; ++j) {
            auto x = p[j][i];
            if (i == j || x == 0)
                continue;
            for (int k = i; k < n; ++k)
                p[j][k] = (p[j][k] - x * p[i][k]) % MOD;
        }
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        init(n);
        for (int i = 0; i < m; ++i) {
            int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            g[x][y] = g[y][x] = w;
            ++d[x], ++d[y];
        }

        ll ans = 0;
        for (int b = 0; b < 32; ++b) {
            for (int i = 0; i < n - 1; ++i)
                for (int j = 0; j < n - 1; ++j)
                    p[i][j] = (d[i + 1] - ((g[i + 1][j + 1] >> b) & 1)) % MOD;

            ans = (ans + (1LL << b) % MOD * det(n - 1)) % MOD;
        }
        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j < n - 1; ++j)
                p[i][j] = (d[i + 1] - g[i + 1][j + 1]) % MOD;

        ans = ans * quick_pow(det(n - 1), MOD - 2) % MOD;

        ans = (ans + MOD) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
