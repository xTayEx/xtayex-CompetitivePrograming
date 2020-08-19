#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
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
#define INF 1LL << 45
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char dir[maxn], newdir[maxn];
vector<int> ID[maxn];
ll dijdis[maxn];
bool vis[maxn];
struct edge {
    int v;
    ll dis;
    edge(int v, ll dis)
    {
        this->v = v, this->dis = dis;
    }
    bool operator>(const edge& e) const
    {
        return dis > e.dis;
    }
};
vector<edge> G[maxn];
priority_queue<edge, vector<edge>, greater<edge>> que;
void dijkstra(int st, int n)
{
    fill(dijdis, dijdis + n + 1, INF);
    fill(vis, vis + n + 1, 0);
    while (!que.empty()) {
        que.pop();
    }
    dijdis[st] = 0, que.push({ st, dijdis[st] });
    while (!que.empty()) {
        int u = que.top().v;
        que.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = 1;
        int len = G[u].size();
        for (int i = 0; i < len; i++) {
            int v = G[u][i].v;
            int D = G[u][i].dis;
            if (!vis[v] && dijdis[v] > dijdis[u] + D) {
                dijdis[v] = dijdis[u] + D;
                que.push({ v, dijdis[v] });
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    int n, m, s, t, x;
    while (T--) {
        scanf("%d%d%d%d%d", &n, &m, &s, &t, &x);
        scanf("%s", dir + 1);
        int tot = 0;
        for (int i = 1; i <= n; i++) {
            ID[i].clear();
            if (dir[i] == 'M') {
                ID[i].emplace_back(tot + 1);
                ID[i].emplace_back(tot + 2);
                newdir[tot + 1] = 'L', newdir[tot + 2] = 'R';
                tot += 2;
            } else {
                ID[i].emplace_back(tot + 1);
                newdir[tot + 1] = dir[i];
                tot++;
            }
        }
        for (int i = 0; i <= tot; i++) {
            G[i].clear();
        }
        int a, b, d;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", &a, &b, &d);
            for (auto node1 : ID[a]) {
                for (auto node2 : ID[b]) {
                    ll dis = d + (newdir[node1] == newdir[node2] ? 0 : x);
                    G[node1].emplace_back(node2, dis);
                    G[node2].emplace_back(node1, dis);
                }
            }
        }
        int ss = 0, tt = ++tot;
        for (auto it : ID[s]) {
            G[it].emplace_back(ss, 0);
            G[ss].emplace_back(it, 0);
        }
        for (auto it : ID[t]) {
            G[it].emplace_back(tt, 0);
            G[tt].emplace_back(it, 0);
        }
        dijkstra(ss, tot + 1);
        printf("%lld\n", dijdis[tt]);
    }
    return 0;
}
