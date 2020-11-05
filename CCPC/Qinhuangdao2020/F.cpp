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
const int maxn = 3e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int fa[maxn];
int ecnt[maxn], vcnt[maxn];
bool vis[maxn];
int n, m;
inline void init()
{
    for (int i = 0; i <= n; i++) {
        fa[i] = i;
        ecnt[i] = 0, vcnt[i] = 1;
        vis[i] = 0;
    }
}
inline int findr(int u)
{
    if (u == fa[u]) return u;
    return fa[u] = findr(fa[u]);
}
int ans;
void mix(int x, int y)
{
    int fx = findr(x);
    int fy = findr(y);
    if (fx != fy) {
        fa[fy] = fx;
        vcnt[fx] += vcnt[fy];
        ecnt[fx] += (1 + ecnt[fy]);
        //debug(ecnt[fx]);
    } else {
        ecnt[fy]++;
        //debug(ecnt[fy]);
    }
}
void solve()
{
    for (int i = 1; i <= n; i++) {
        if (!vis[fa[i]]) {
            //debug(fa[i]);
            //debug(ecnt[fa[i]] - vcnt[fa[i]]);
            ans += max((ecnt[fa[i]] - vcnt[fa[i]]), 0);
            vis[fa[i]] = 1;
        }
    }
}
int main()
{
    int kase = 0;
    int T;
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d%d", &n, &m);
        init();
        int x, y;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &x, &y);
            mix(x, y);
        }
        solve();
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
