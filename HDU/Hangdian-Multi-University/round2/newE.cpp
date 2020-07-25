#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 5, M = 1e6 + 5, INF = 0x7f7f7f7f;

struct edge {
    int to, w;
    ll cost;
    int next;
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

ll d[N];
int vis[N], flow[N], fa[N], last[N];

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

ll ans[N];

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
using pll = pair<ll, ll>;
vector<ll> vec;
vector<pll> pvec;

ll a[N], b[N], c[N];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        vec.clear();
        pvec.clear();
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i] >> c[i];
            if (-b[i] < 2 * a[i]) {
                for (int j = 1; j <= n && j <= m; ++j)
                    pvec.emplace_back(i, j), vec.emplace_back(j);

            } else {
                for (int j = -b[i] / 2 * a[i], k = 0; j >= 1 && k <= n / 2; ++k, --j)
                    pvec.emplace_back(i, j), vec.emplace_back(j);

                for (int j = -b[i] / 2 * a[i] + 1, k = 0; j <= m && k <= n / 2; ++k, ++j)
                    pvec.emplace_back(i, j), vec.emplace_back(j);
            }
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());

        init(), m = vec.size();
        int s = 0, t = n + m + 1;
        for (auto& p : pvec) {
            ll u = p.first, v = p.second, val = a[u] * v * v + b[u] * v + c[u];
            v = lower_bound(vec.begin(), vec.end(), v) - vec.begin() + (n + 1);
            add_flow(u, v, 1, val);
        }

        for (int i = 0; i < vec.size(); ++i)
            add_flow(i + n + 1, t, 1, 0);

        for (int i = 1; i <= n; ++i)
            add_flow(s, i, 1, 0);

        ll maxflow, mincost;
        mcmf(s, t, maxflow, mincost);

        for (int i = 1; i <= maxflow; ++i) {
            cout << ans[i] << ' ';
        }
    }
    return 0;
}
