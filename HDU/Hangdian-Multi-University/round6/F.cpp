
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define debug printf("debug\n")
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 2e5 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[maxn];
int n, m;
struct EDGE {
    int to, nxt, w;
};
struct Edge {
    int u, v, w;
    int operator<(const Edge& b) const
    {
        return w < b.w;
    }
} e[maxn];
EDGE edge[maxn * 2];
int head[maxn], tot = 0;
void add(int u, int v, int w)
{
    edge[tot] = { v, head[u], w };
    head[u] = tot++;
}
void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}

ll mod = 1e9 + 7;
ll tw[maxn];
void ini()
{
    tw[1] = 2;
    for (int i = 2; i <= maxn; i++) {
        tw[i] = (2 * tw[i - 1]) % mod;
    }
}
int fa[maxn];
int find(int u)
{
    if (u != fa[u]) {
        fa[u] = find(fa[u]);
    }
    return fa[u];
}
void getT()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int pa = find(e[i].u), pb = find(e[i].v);
        if (pa != pb) {
            fa[pa] = pb;
            cnt++;
            add(e[i].u, e[i].v, e[i].w);
            add(e[i].v, e[i].u, e[i].w);
            if (cnt == n - 1)
                break;
        }
    }
}
int o[maxn], z[maxn];
void dfs(int u, int fa)
{
    for (int i = head[u]; i != -1; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v != fa) {
            dfs(v, u);
            o[u] += o[v];
            z[u] += z[v];
        }
    }
    if (a[u])
        o[u]++;
    else
        z[u]++;
}
ll ans = 0;
void dfs2(int u, int fa)
{
    for (int i = head[u]; i != -1; i = edge[i].nxt) {
        int v = edge[i].to, w = edge[i].w;
        if (v != fa) {
            ans = (ans + (1ll * (o[1] - o[v]) * z[v] + 1ll * o[v] * (z[1] - z[v])) % mod * tw[w]) % mod;
            dfs2(v, u);
        }
    }
}
void cul()
{
    memset(o, 0, sizeof(o));
    memset(z, 0, sizeof(z));
    dfs(1, -1);
    dfs2(1, -1);
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int t;
    ini();
    cin >> t;
    while (t--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> e[i].u >> e[i].v;
            e[i].w = i;
        }
        getT();
        cul();
        cout << ans << endl;
    }
    return 0;
}
