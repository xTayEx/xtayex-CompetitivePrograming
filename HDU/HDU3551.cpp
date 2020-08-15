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
#define idebug(x) printf("%s = %d\n", #x, x)
#define ddebug(x) printf("%s = %lf\n", #x, x)
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 20005 + 5;
const int maxm = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct edge {
    int u, v;
    edge(int u, int v)
        : u(u)
        , v(v)
    {
    }
};
struct Edge {
    int v, nxt;
} G[maxm];
vector<edge> es;
int id[maxn][maxn];
int d[maxn], ft[maxn], match[maxn], pre[maxn], type[maxn];
int que[500005], qhead, qtail;
int head[maxn], cnt;
inline int read()
{
    char ch;
    int s = 1;
    do {
        ch = getchar();
        if (ch == '-')
            s = -1;
    } while (ch > '9' || ch < '0');
    int ret = 0;
    while (ch >= '0' && ch <= '9') {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    return ret * s;
}
inline void addedge(int x, int y)
{
    G[cnt].v = y;
    G[cnt].nxt = head[x];
    head[x] = cnt++;

    G[cnt].v = x;
    G[cnt].nxt = head[y];
    head[y] = cnt++;
}
inline int findr(int x)
{
    return ft[x] == x ? x : ft[x] = findr(ft[x]);
}
inline int get_lca(int u, int v)
{
    static int ss[maxn], tim;
    tim++;
    while (ss[u] != tim) {
        if (u) {
            ss[u] = tim;
            u = findr(pre[match[u]]);
        }
        swap(u, v);
    }
    return u;
}
inline void flower(int x, int y, int p)
{
    while (findr(x) != p) {
        pre[x] = y;
        y = match[x];
        ft[x] = ft[y] = p;
        if (type[y] == 1) {
            que[qtail++] = y;
            type[y] = 2;
        }
        x = pre[y];
    }
}
inline bool blossom(int u, int n)
{
    qhead = qtail = 0;
    for (int i = 1; i <= n; i++) {
        type[i] = 0, ft[i] = i;
    }
    que[qtail++] = u, type[u] = 2;
    while (qhead != qtail) {
        u = que[qhead++];
        for (int i = head[u]; i != -1; i = G[i].nxt) {
            int v = G[i].v;
            if (type[v] == 0) {
                type[v] = 1;
                pre[v] = u;
                if (!match[v]) {
                    while (u) {
                        u = match[pre[v]];
                        match[v] = pre[v];
                        match[match[v]] = v;
                        v = u;
                    }
                    return 1;
                } else {
                    que[qtail++] = match[v];
                    type[match[v]] = 2;
                }
            } else if (type[v] == 2 && findr(u) != findr(v)) {
                int p = get_lca(u, v);
                flower(u, v, p), flower(v, u, p);
            }
        }
    }
    return 0;
}
inline void init(int n, int m)
{
    mst(head, -1), cnt = 0;
    es.clear();
    mst(match, 0);
}
int main()
{
    int T, kase = 1;
    T = read();
    while (T--) {
        int tot = 0;
        int n, m;
        n = read(), m = read();
        init(n, m);
        for (int i = 1; i <= m; i++) {
            int u, v;
            u = read(), v = read();
            es.push_back({ u, v });
        }
        for (int i = 1; i <= n; i++) {
            d[i] = read();
            for (int j = 0; j < d[i]; j++) {
                id[i][j] = ++tot;
            }
        }
        int sz = es.size();
        for (int i = 0; i < sz; i++) {
            int u = es[i].u, v = es[i].v;
            addedge(tot + 1, tot + 2);
            for (int j = 0; j < d[u]; j++) {
                addedge(id[u][j], tot + 1);
            }
            for (int j = 0; j < d[v]; j++) {
                addedge(tot + 2, id[v][j]);
            }
            tot += 2;
        }
        int ans = 0;
        for (int i = 1; i <= tot; i++) {
            if (!match[i] && blossom(i, tot)) {
                ans++;
            }
        }
        printf("Case %d: %s\n", kase++, 2 * ans == tot ? "YES" : "NO");
    }
    return 0;
}
