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
#define debug(x) cerr << "\033[01;34m" << #x << " = " << x << "\033[0m" \
                      << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 4e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
vector<int> g[maxn];
int siz[maxn], rt, n;
void dfs1(int u, int fa)
{
    siz[u] = 1;
    int sz = g[u].size();
    bool flag = 1;
    for (int i = 0; i < sz; i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[v] > n / 2) flag = 0;
    }
    if (n - siz[u] > n / 2) flag = 0;
    if (flag) rt = u;
}
int maxson[maxn][2];
int fa[maxn];
void dfs2(int u)
{
    siz[u] = 1;
    int sz = g[u].size();
    for (int i = 0; i < sz; i++) {
        int v = g[u][i];
        if (v == fa[u]) continue;
        fa[v] = u;
        dfs2(v);
        siz[u] += siz[v];
        if (siz[v] > n / 2) continue;
        if (siz[v] > maxson[u][0])
            maxson[u][1] = maxson[u][0], maxson[u][0] = siz[v];
        else if (siz[v] > maxson[u][1])
            maxson[u][1] = siz[v];
    }
}
int out[maxn]; // 点u外最大的且大小不超过n/2的子树的大小
bool ans[maxn]; // u是否可行
// maxi: 用来更新out
void dfs3(int u, int maxi)
{
    out[u] = maxi;
    int sz = g[u].size();
    for (int i = 0; i < sz; i++) {
        int v = g[u][i];
        if (v == fa[u]) continue;
        if (n - siz[u] <= n / 2) maxi = max(maxi, n - siz[u]);
        if (maxson[u][0] == siz[v]) {
            int tmp = max(maxi, maxson[u][1]);
            dfs3(v, tmp);
        } else {
            int tmp = max(maxi, maxson[u][0]);
            dfs3(v, tmp);
        }
    }
    if (n - siz[u] - out[u] <= n / 2 || rt == u) {
        ans[u] = 1;
    }
}
int main()
{
    scanf("%d", &n);
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, -1);
    fa[rt] = -1;
    dfs2(rt);
    //for (int i = 1; i <= n; i++) {
        //debug(i);
        //debug(siz[i]);
        //debug(maxson[i][0]);
        //debug(maxson[i][1]);
        //puts("----------------------------");
    //}
    dfs3(rt, 0);
    //for (int i = 1; i <= n; i++) {
        //debug(i);
        //debug(out[i]);
        //puts("=======================");
    //}
    for (int i = 1; i <= n; i++) {
        printf("%d%c", ans[i] ? 1 : 0, i == n ? '\n' : ' ');
    }
    return 0;
}
