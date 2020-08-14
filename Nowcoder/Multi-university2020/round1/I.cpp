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
#define idebug(x) printf("%s = %d\n", #x, x);
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 500 + 5;
const int maxm = 105;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int d[maxn];
vector<int> G[maxn];
int id[maxn * 4][2];
int match[maxn * 4], pre[maxn * 4], type[maxn * 4];
int que[maxn * 4], qhead, qtail;
int ft[maxn];
inline int find(int x)
{
    if (ft[x] == x)
        return x;
    return ft[x] = find(ft[x]);
}
inline int get_lca(int u, int v)
{
    static int ss[maxn * 4], tim;
    tim++;
    while (ss[u] != tim) {
        if (u) {
            ss[u] = tim, u = find(pre[match[u]]);
        }
        swap(u, v);
    }
    return u;
}
inline void flower(int x, int y, int p)
{
    while (find(x) != p) {
        pre[x] = y, y = match[x];
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
        type[i] = 0;
        ft[i] = i;
    }
    que[qtail++] = u;
    type[u] = 2;
    while (qhead != qtail) {
        u = que[qhead++];
        int sz = G[u].size();
        for (int i = 0; i < sz; i++) {
            int v = G[u][i];
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
            } else if (type[v] == 2 && find(u) != find(v)) {
                int p = get_lca(u, v);
                flower(u, v, p), flower(v, u, p);
            }
        }
    }
    return 0;
}
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        int nowid = 1;
        for (int i = 1; i <= 2 * (n + m); i++) {
            G[i].clear(),match[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &d[i]);
            if (d[i] == 2) {
                id[i][0] = nowid++, id[i][1] = nowid++;
            } else {
                id[i][0] = nowid++;
            }
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[nowid].emplace_back(nowid + 1);
            G[nowid + 1].emplace_back(nowid);
            for (int i = 0; i < d[u]; i++) {
                G[id[u][i]].emplace_back(nowid);
                G[nowid].emplace_back(id[u][i]);
            }
            for (int i = 0; i < d[v]; i++) {
                G[id[v][i]].emplace_back(nowid + 1);
                G[nowid + 1].emplace_back(id[v][i]);
            }
            nowid += 2;
        }
        int ans = 0;
        for (int i = 1; i < nowid; i++) {
            if (!match[i]) {
                ans += blossom(i, nowid - 1);
            }
        }
        idebug(ans);
        idebug(nowid);
        printf("%s\n", 2 * ans == (nowid - 1) ? "Yes" : "No");
    }
    return 0;
}
