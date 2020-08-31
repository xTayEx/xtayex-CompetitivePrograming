#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 300 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll w[305][305];
bool vx[maxn], vy[maxn];
ll lx[maxn], ly[maxn], slack[maxn];
int ml[maxn], mr[maxn], pre[maxn];
int que[maxn];
inline void setCrossRoad(int& v)
{
    for (; v; swap(v, mr[pre[v]])) {
        ml[v] = pre[v];
    }
}
inline void bfs(int u, int n)
{
    int head = 0, tail = 0;
    que[tail++] = u;
    vx[u] = 1;
    while (1) {
        while (head != tail) {
            int u = que[head++];
            for (int v = 1; v <= n; v++) {
                if (vy[v]) {
                    continue;
                }
                ll d = lx[u] + ly[v] - w[u][v];
                if (d > slack[v]) {
                    continue;
                }
                pre[v] = u;
                if (d == 0) {
                    if (!ml[v]) {
                        setCrossRoad(v);
                        return;
                    }
                    vy[v] = vx[ml[v]] = 1;
                    que[tail++] = ml[v];
                } else {
                    slack[v] = d;
                }
            }
        }
        ll d = INF;
        int to = 1;
        for (int v = 1; v <= n; v++) {
            if (!vy[v] && d > slack[v]) {
                d = slack[v], to = v;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (vx[i]) lx[i] -= d;
            if (vy[i]) {
                ly[i] += d;
            } else {
                slack[i] -= d;
            }
        }
        if (!ml[to]) {
            setCrossRoad(to);
            return;
        }
        head = tail = 0;
        que[tail++] = ml[to];
        vx[ml[to]] = vy[to] = 1;
    }
}
inline ll KM(int n)
{
    for (int i = 1; i <= n; i++) {
        ly[i] = 0, ml[i] = mr[i] = 0;
        lx[i] = *max_element(w[i] + 1, w[i] + 1 + n);
    }
    for (int i = 1; i <= n; i++) {
        fill(vx, vx + 1 + n, 0), fill(vy, vy + 1 + n, 0), fill(slack, slack + 1 + n, INF);
        bfs(i, n);
    }
    return accumulate(lx + 1, lx + 1 + n, 0LL) + accumulate(ly + 1, ly + 1 + n, 0LL);
}
int main()
{
    ll val;
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%lld", &val);
                w[i][j] = val;
            }
        }
        ll ans = KM(n);
        printf("%lld\n", ans);
    }
    return 0;
}
