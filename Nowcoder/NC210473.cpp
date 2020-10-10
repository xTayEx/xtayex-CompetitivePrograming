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
#define debug(x) cerr << "\033[01;34m" << #x << " = " << x << "\033[0m" << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e3 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct node {
    int to;
    int d;
    node(int to, int d)
    {
        this->to = to;
        this->d = d;
    }
};
vector<node> g[maxn];
ll f[maxn];
int n, m;
void dfs(int u, int fa, int lim)
{
    f[u] = 0;
    int cnt = 0;
    int sz = g[u].size();
    for (int i = 0; i < sz; i++) {
        int v = g[u][i].to;
        if (v == fa) continue;
        dfs(v, u, lim);
        int dv = g[u][i].d;
        f[u] += min((dv <= lim ? dv : INF) * 1LL, f[v]);
        cnt++;
    }
    if (cnt == 0) f[u] = INF;
}
int solve()
{
    int lef = 1, rig = 1e6;
    while (lef < rig) {
        int mid = (rig + lef) / 2;
        dfs(1, 0, mid);
        if (f[1] > m)
            lef = mid + 1;
        else
            rig = mid;
    }
    return lef;
}
int main()
{
    debug(maxn);
    scanf("%d%d", &n, &m);
    int u, v, d;
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d", &u, &v, &d);
        g[u].emplace_back(v, d);
        g[v].emplace_back(u, d);
    }
    int ans = solve();
    dfs(1, 0, ans);
    ans = (f[1] <= m ? ans : -1);
    printf("%d\n", ans);
    return 0;
}
