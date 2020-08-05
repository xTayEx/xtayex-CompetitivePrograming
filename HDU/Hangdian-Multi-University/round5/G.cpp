#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 2e5 + 5;

struct edge {
    int to, weight;
};
vector<edge> g[N];
ll dp[N][2], sum[N];

void init(int n)
{
    for (int i = 0; i <= n; ++i) {
        sum[i] = -1;
        dp[i][0] = dp[i][1] = -1;
        g[i].clear();
    }
}

ll dfs1(int u, int fa)
{
    ll tot = 0;
    for (auto e : g[u]) {
        if (e.to != fa) {
            tot += dfs1(e.to, u) + e.weight;
        }
    }
    return sum[u] = tot;
}

ll dfs2(int u, int fa, int k, bool limit)
{
    if (~dp[u][limit])
        return dp[u][limit];
    ll ans = 0;
    if ((int)g[u].size() > k && limit) {
        vector<ll> vec;

        for (auto e : g[u])
            if (e.to != fa)
                vec.emplace_back(dfs2(e.to, u, k, false) + e.weight);

        vec.emplace_back(sum[1] - sum[u]);
        sort(vec.begin(), vec.end(), greater<ll>());
        for (int i = 0; i < k; ++i)
            ans += vec[i];
    } else {
        for (auto e : g[u]) {
            if (e.to != fa)
                ans += dfs2(e.to, u, k, limit) + e.weight;
        }
    }
    return dp[u][limit] = ans;
}

int main()
{
    int q;
    scanf("%d", &q);
    while (q--) {
        int n, k;
        scanf("%d%d", &n, &k);
        init(n);
        for (int i = 1; i < n; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            g[u].emplace_back(edge{ v, w });
            g[v].emplace_back(edge{ u, w });
        }
        ll ans = -1;
        for (int i = 1; i <= n; ++i) {
            if (sum[i] == -1)
                dfs1(i, i);

            ans = max(dfs2(i, 0, k, true), ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
