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
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define debug(x) cerr << "\033[01;31m" << #x << " = " << x << "\033[0m" \
                      << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 5e4 + 5;
const int maxm = 1e2 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct node {
    int v, w;
    node(int v, int w)
    {
        this->v = v, this->w = w;
    }
};
vector<node> g[maxn];
bool b[maxn];
int siz[maxn];
ll f[maxn][maxm];
int n, m, k;
void dfs(int u, int fa)
{
    f[u][0] = 0;
    if (b[u]) {
        siz[u] = 1, f[u][1] = 0;
    }
    int sz = g[u].size();
    for (int i = 0; i < sz; i++) {
        int v = g[u][i].v;
        int w = g[u][i].w;
        if (v == fa) continue;
        dfs(v, u);
        siz[u] += siz[v];
        int X = min(siz[u], k);
        int Y = min(siz[v], k);
        for (int p = X; p >= 1; p--) {
            for (int q = 1; q <= min(p, Y); q++) {
                f[u][p] = min(f[u][p], f[u][p - q] + f[v][q] + (k - q) * q * w * 1LL);
            }
        }
    }
}
int main()
{
    mst(f, INF);
    scanf("%d%d%d", &n, &m, &k);
    vector<int> vi;
    for (int i = 1; i <= m; i++) {
        int tmp;
        scanf("%d", &tmp);
        b[tmp] = 1;
    }
    for (int i = 1; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back(node(b, c));
        g[b].push_back(node(a, c));
    }
    dfs(1, -1);
    ll ans = f[1][k];
    printf("%lld\n", ans);
    return 0;
}
