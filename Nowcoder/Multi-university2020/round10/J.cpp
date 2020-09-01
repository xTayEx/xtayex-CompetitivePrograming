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
#define idebug(x) printf("%s = %d\n", #x, x)
#define ddebug(x) printf("%s = %lf\n", #x, x)
#define INF 1005 // INF设太大的话会爆掉，1005已经足够了，因为n <= 500
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 500 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
bool vx[maxn], vy[maxn];
int lx[maxn], ly[maxn], slack[maxn], w[maxn][maxn];
int ml[maxn], mr[maxn], pre[maxn];
int que[maxn];
int dp[maxn][maxn];
vector<int> tr1[maxn], tr2[maxn];
int rt1, rt2;
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
                int d = lx[u] + ly[v] - w[u][v];
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
        int d = INF;
        int to = 1;
        for (int v = 1; v <= n; v++) {
            if (!vy[v] && d > slack[v]) {
                d = slack[v], to = v;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (vx[i]) lx[i] -= d;
            if (vy[i])
                ly[i] += d;
            else
                slack[i] -= d;
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
inline int KM(int n)
{
    for (int i = 1; i <= n; i++) {
        ly[i] = 0, ml[i] = mr[i] = 0;
        lx[i] = *max_element(w[i] + 1, w[i] + 1 + n);
    }
    for (int i = 1; i <= n; i++) {
        fill(vx, vx + 1 + n, 0);
        fill(vy, vy + 1 + n, 0);
        fill(slack, slack + 1 + n, INF);
        bfs(i, n);
    }
    int ret = accumulate(lx + 1, lx + 1 + n, 0) + accumulate(ly + 1, ly + 1 + n, 0);
    return ret;
}
void solve(int x, int y)
{
    if (tr1[x].size() != tr2[y].size()) {
        dp[x][y] = INF;
        return;
    }
    if (x != y) dp[x][y]++;
    if (tr1[x].empty()) return;
    for (int i = 0; i < (int)tr1[x].size(); i++) {
        for (int j = 0; j < (int)tr2[y].size(); j++) {
            solve(tr1[x][i], tr2[y][j]);
        }
    }
    for (int i = 0; i < (int)tr1[x].size(); i++) {
        for (int j = 0; j < (int)tr2[y].size(); j++) {
            w[i + 1][j + 1] = -dp[tr1[x][i]][tr2[y][j]];
        }
    }
    int tmp = -KM(tr1[x].size());
    if (tmp >= INF)
        dp[x][y] = INF;
    else
        dp[x][y] += tmp;
}
int main()
{
    int n;
    scanf("%d", &n);
    int tmp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        if (tmp == 0)
            rt1 = i;
        else
            tr1[tmp].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        if (tmp == 0)
            rt2 = i;
        else
            tr2[tmp].push_back(i);
    }
    solve(rt1, rt2);
    printf("%d\n", dp[rt1][rt2]);
    return 0;
}
