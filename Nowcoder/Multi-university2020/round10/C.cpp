#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5 + 5, M = 2e5 + 5;
struct edge {
    int to, next, weight;
} edges[M << 1];
int head[N], a[N], pre[N], tot;
int fa[N], id[N];
bool disable[N];

void init(int n)
{
    memset(head + 1, -1, sizeof(int) * n);
    tot = 0;
}

void add_edge(int u, int v, int w)
{
    edges[tot] = { v, head[u], w };
    head[u] = tot++;
}

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void dfs(int u, int fa)
{
    pre[u] = fa;
    for (int i = head[u]; ~i; i = edges[i].next) {
        int v = edges[i].to, w = edges[i].weight;
        if (v == fa)
            continue;
        a[v] = w;
        dfs(v, u);
    }
}

void solve(int n)
{
    for (int i = 0; i <= n; ++i) {
        fa[i] = i;
        id[i] = i;
        disable[i] = 1;
    }

    sort(id + 1, id + 1 + n, [](int x, int y) {
        return a[x] > a[y];
    });

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int u = id[i];
        disable[u] = false;
        for (int j = head[u]; ~j; j = edges[j].next) {
            int v = edges[j].to, fv = find(v);
            if (disable[v])
                continue;
            ans += a[fv] - a[u];
            fa[fv] = u;
        }
    }

    for (int i = 1; i <= n; ++i)
        if (find(i) == i)
            ans += a[i];

    printf("%lld\n", ans);
}

int main()
{
    int n, q;

    scanf("%d%d", &n, &q);
    init(n);

    for (int i = 1; i < n; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    dfs(1, 0);
    pre[1] = 0, a[1] = 0;
    for (int i = head[1]; ~i; i = edges[i].next)
        a[1] = max(a[1], edges[i].weight);

    solve(n);

    while (q--) {
        int p, w;
        scanf("%d%d", &p, &w), p = (p - 1) * 2;
        int u = edges[p].to, v = edges[p ^ 1].to;
        if (pre[u] == 0 || pre[v] == 0)
            a[1] = max(a[1], w);
        if (pre[u] == v)
            a[u] = w;
        if (pre[v] == u)
            a[v] = w;
        solve(n);
    }
    return 0;
}
