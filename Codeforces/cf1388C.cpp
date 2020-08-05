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
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int p[maxn], h[maxn], g[maxn], siz[maxn], adj[maxn];
vector<int> graph[maxn];
inline void init(int n)
{
    for (int i = 0; i <= n; i++) {
        graph[i].clear();
        siz[i] = p[i], adj[i] = 0;
    }
}
void dfs(int u, int fa)
{
    int sz = graph[u].size();
    for (int i = 0; i < sz; i++) {
        int v = graph[u][i];
        if (v == fa)
            continue;
        dfs(v, u);
        siz[u] += siz[v];
    }
}
void dfs1(int u, int fa)
{
    int sz = graph[u].size();
    for (int i = 0; i < sz; i++) {
        int v = graph[u][i];
        if (v == fa)
            continue;
        adj[u] += g[v];
        dfs1(v, u);
    }
}
void Debug(int n)
{
    puts("---------------siz----------------");
    for (int i = 1; i <= n; i++) {
        printf("%d ", siz[i]);
    }
    puts("\n----------------------------------");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &h[i]);
        }
        init(n);
        int u, v;
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &u, &v);
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        dfs(1, -1);
        //Debug(n);
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            if ((siz[i] + h[i]) % 2 != 0) {
                flag = 0;
            }
            g[i] = (siz[i] + h[i]) / 2;
            if (g[i] > siz[i]) {
                flag = 0;
            }
        }
        dfs1(1, -1);
        for (int i = 1; i <= n; i++) {
            if (adj[i] > g[i]) {
                flag = 0;
                break;
            }
        }
        if (flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
