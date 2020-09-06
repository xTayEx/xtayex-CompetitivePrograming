#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
const long long mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll ps[maxn];
vector<int> G[maxn];
int siz[maxn];
void dfs(int u, int fa)
{
    siz[u] = 1;
    int sz = G[u].size();
    for (int i = 0; i < sz; i++) {
        int v = G[u][i];
        if (v == fa) continue;
        dfs(v, u);
        siz[u] += siz[v];
    }
}
struct node {
    ll x, y;
    bool operator<(const node& nn) const
    {
        return x * y > (nn.x) * (nn.y);
    }
};
node ns[maxn];
inline void init(int n)
{
    for (int i = 0; i <= n; i++) {
        G[i].clear();
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        init(n);
        int u, v;
        for (int i = 1; i <= n - 1; i++) {
            scanf("%d%d", &u, &v);
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
        int m;
        scanf("%d", &m);
        ll p;
        for (int i = 1; i <= m; i++) {
            scanf("%lld", &p);
            ps[i] = p;
        }
        sort(ps + 1, ps + 1 + m, greater<ll>());
        dfs(1, -1);
        int idx = 0;
        for (int i = 2; i <= n; i++) {
            ns[++idx] = { 1LL * siz[i], 1LL * (n - siz[i]) };
        }
        sort(ns + 1, ns + 1 + idx);
        ll ans = 0;
        if (m <= n - 1) {
            for (int i = 1; i <= m; i++) {
                ans = (ans % mod + ns[i].x % mod * ns[i].y % mod * ps[i] % mod) % mod;
            }
            for (int i = m + 1; i <= idx; i++) {
                ans = (ans % mod + ns[i].x % mod * ns[i].y % mod) % mod;
            }
        } else {
            ll tmp = 1;
            for (int i = 1; i <= m - n + 2; i++) {
                tmp = (tmp * ps[i]) % mod;
            }
            ans = (ans % mod + tmp % mod * ns[1].x % mod * ns[1].y % mod) % mod;
            for (int i = m - n + 3; i <= m; i++) {
                ans = (ans % mod + ns[i - (m - n + 1)].x % mod * ns[i - (m - n + 1)].y % mod * ps[i] % mod) % mod;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
