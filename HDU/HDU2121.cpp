#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define debug printf("debug\n")
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e3 + 5;
const int maxm = 2e4 + 5;
const long long INF = std::numeric_limits<long long>::max(); 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct edge {
    int u;
    int v;
    ll cost;
};
edge es[maxm];
int pre[maxn];
int id[maxn];
int vis[maxn];
ll inedge[maxn];
int ansnode;
ll zhuliu(int root, int n, int m, edge E[])
{
    ll res = 0;
    int v;
    while (1) {
        for (int i = 0; i < n; i++) {
            inedge[i] = INF;
        }
        for (int i = 0; i < m; i++) {
            if (es[i].u != es[i].v && es[i].cost < inedge[es[i].v]) {
                pre[es[i].v] = es[i].u;
                inedge[es[i].v] = es[i].cost;
                if (es[i].u == root) {
                    ansnode = i;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (i != root && inedge[i] == INF) {
                return -1;
            }
        }
        mst(id, -1);
        mst(vis, -1);
        int tn = 0;
        inedge[root] = 0;
        for (int i = 0; i < n; i++) {
            res += inedge[i];
            v = i;
            while (vis[v] != i && id[v] == -1 && v != root) {
                vis[v] = i;
                v = pre[v];
            }
            if (v != root && id[v] == -1) {
                for (int u = pre[v]; u != v; u = pre[u]) {
                    id[u] = tn;
                }
                id[v] = tn++;
            }
        }
        if (tn == 0)
            break;
        for (int i = 0; i < n; i++) {
            if (id[i] == -1) {
                id[i] = tn++;
            }
        }
        for (int i = 0; i < m; i++) {
            v = es[i].v;
            es[i].u = id[es[i].u];
            es[i].v = id[es[i].v];
            if (es[i].u != es[i].v) {
                es[i].cost -= inedge[v];
            }
        }
        n = tn;
        root = id[root];
    }
    return res;
}
int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int S, T;
        ll C;
        //int ecnt=0;
        ll sum = 0;
        int vir = -1;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %lld", &S, &T, &C);
            if (S == T) {
                i--;
                m--;
                continue;
            }
            es[i] = { S, T, 1LL * C };
            sum += C;
        }
        vir = n;
        for (int i = m; i < n + m; i++) {
            es[i] = { vir, i - m, 1LL * (sum + 1) };
        }
        //printf("ecnt==n+m is %d\n",ecnt==n+m);
        ll res = zhuliu(vir, n + 1, n + m, es);
        if (res > 2 * (sum + 1)) {
            puts("impossible");
        } else {
            printf("%lld %d\n", res - sum - 1, ansnode - m);
        }
        puts("");
    }
    return 0;
}
