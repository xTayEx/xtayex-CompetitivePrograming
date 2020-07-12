
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

const int N = 1e2 + 5, M = 2e3 + 5, INF = 0x7f7f7f7f;

struct edge {
    int to, w, cost, next;
} edges[M << 1];

int head[N], tot;

inline void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}

inline void add_edge(int u, int v, int w, int cost)
{
    edges[tot] = { v, w, cost, head[u] };
    head[u] = tot++;
}

inline void add_flow(int u, int v, int f, int cost)
{
    add_edge(u, v, f, cost);
    add_edge(v, u, 0, -cost);
}

int vis[N], d[N], flow[N], fa[N], last[N];

bool spfa(int s, int t)
{
    memset(vis, 0, sizeof(vis));
    memset(flow, 0x7f, sizeof(flow));
    memset(d, 0x7f, sizeof(d));
    std::queue<int> que;
    que.push(s), vis[s] = 1, d[s] = 0, fa[t] = -1;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        vis[u] = 0;
        for (int i = head[u]; ~i; i = edges[i].next) {
            int v = edges[i].to;
            if (edges[i].w > 0 && d[v] > d[u] + edges[i].cost) {
                d[v] = d[u] + edges[i].cost;
                fa[v] = u;
                last[v] = i;
                flow[v] = std::min(flow[u], edges[i].w);
                if (!vis[v]) {
                    vis[v] = 1;
                    que.push(v);
                }
            }
        }
    }
    return fa[t] != -1;
}

int ans[N];

void mcmf(int s, int t, ll& maxflow, ll& mincost)
{
    maxflow = 0, mincost = 0;
    while (spfa(s, t)) {
        int u = t;
        maxflow += flow[t];
        mincost += flow[t] * d[t];
        ans[maxflow] = mincost;
        while (u != s) {
            edges[last[u]].w -= flow[t];
            edges[last[u] ^ 1].w += flow[t];
            u = fa[u];
        }
    }
}

ll gcd(ll a, ll b)
{
    return !b ? a : gcd(b, a % b);
}

int n, m, s, t;

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
    while (~scanf("%d%d", &n, &m)) {
        init();
        s = 1, t = n;
        for (int i = 0; i < m; ++i) {
            int u = read(), v = read(), cost = read();
            add_flow(u, v, 1, cost);
        }

        ll maxflow, mincost;
        mcmf(s, t, maxflow, mincost);

        int maxlimit = maxflow;

        int q = read();
        while (q--) {
            int u = read(), v = read();
            if (u == 0 || (v / u == maxlimit && v % u > 0) || v / u > maxlimit) {
                puts("NaN");
                continue;
            }
            int p = v / u;
            ll res = ans[p] * u + (ans[p + 1] - ans[p]) * (v % u);
            ll l = gcd(res, v);
            printf("%lld/%lld\n", res / l, v / l);
        }
    }
    return 0;
}
