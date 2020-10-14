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
#define debug(x) cerr << "\033[01;31m" << #x << " = " << x << "\033[0m" \
                      << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
vector<int> g[maxn];
int siz[maxn];
int n;
void dfs(int u, int fa)
{
    siz[u] = 1;
    int sz = g[u].size();
    for (int i = 0; i < sz; i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u);
        siz[u] += siz[v];
    }
}
double ans[maxn];
void solve(int u, int fa, int dep)
{
    int sz = g[u].size();
    for (int i = 0; i < sz; i++) {
        int v = g[u][i];
        if (v == fa) continue;
        ans[v] = (dep + 1) + 0.5 * (n - (siz[v] - 1) - (dep + 1));
        solve(v, u, dep + 1);
    }
}
int main()
{
    scanf("%d", &n);
    int p;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &p);
        g[i].push_back(p);
        g[p].push_back(i);
    }
    dfs(1, -1);
    ans[1] = 1.0;
    solve(1, -1, 1);
    for (int i = 1; i <= n; i++) {
        printf("%.1lf ", ans[i]);
    }
    return 0;
}
