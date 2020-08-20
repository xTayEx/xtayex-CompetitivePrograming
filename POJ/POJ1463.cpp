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
//#include <unordered_map>
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1500 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct edge {
    int v, nxt;
} es[maxn];
int head[maxn];
int tot;
inline void init()
{
    mst(head, -1);
    tot = 0;
}
inline void addedge(int u, int v)
{
    es[tot].nxt = head[u];
    es[tot].v = v;
    head[u] = tot++;
}
int dp[maxn][2];
int dfs(int u, int fa)
{
    int sum1 = 0, sum2 = 0;
    for (int i = head[u]; i != -1; i = es[i].nxt) {
        int v = es[i].v;
        if (v == fa) continue;
        sum1 += dfs(v, u);
        sum2 += dp[v][1];
    }
    dp[u][0] = sum2, dp[u][1] = sum1 + 1;
    return min(dp[u][0], dp[u][1]);
}
int deg[maxn];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        init();
        for (int i = 1; i <= n; i++) {
            deg[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int u, v, cnt;
            scanf("%d:(%d)", &u, &cnt);
            u++;
            for (int i = 1; i <= cnt; i++) {
                scanf("%d", &v);
                v++, deg[v]++;
                addedge(u, v);
            }
        }
        int rt = -1;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) {
                rt = i;
                break;
            }
        }
        dfs(rt, 0);
        //debug(rt);
        int ans = min(dp[rt][0], dp[rt][1]);
        printf("%d\n", ans);
    }
    return 0;
}
