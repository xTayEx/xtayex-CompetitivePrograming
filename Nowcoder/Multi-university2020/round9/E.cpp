
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
const int maxn = 2e5 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[maxn];
int n, m;
struct EDGE {
    int to, nxt, w;
};
EDGE edge[maxn * 2];
int head[maxn], tot = 0;
void add(int u, int v, int w = 1)
{
    edge[tot] = { v, head[u], w };
    head[u] = tot++;
}
void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}
int way[maxn], ndep = 0, s;
int dfs(int u, int fa, int dep)
{
    if (u == n) {
        ndep = dep;
        return 1;
    }
    for (int i = head[u]; i != -1; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v != fa) {
            if (dfs(v, u, dep + 1) && dep >= m) {
                way[v] = 1;
                if (dep == m)
                    s = u, way[u] = 1;
                return 1;
            }
        }
    }
    return 0;
}
int ans = 0;
int siz[maxn];
void dfs2(int u, int fa, int dep)
{
    siz[u] = dep;
    for (int i = head[u]; i != -1; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v != fa) {
            dfs2(v, u, dep + 1);
        }
    }
}
int getT(int u, int hea)
{
    if (2 * siz[hea] > siz[n] - siz[hea]) { //到达公共节点的时间
        return 0;
    }

    int t = (siz[n] + siz[u] - 2 * siz[hea]) / 2; //n到达u的时间
    if (way[u]) {
        t = (siz[n] - siz[u]) / 2;
    }
    int t2 = siz[u]; //A到达u的时间
    if (t2 > t) {
        return 0;
    } //在u前就被抓到
    return t;
}
void dfs3(int u, int fa, int hea)
{
    if (way[u])
        hea = u;
    if (u == n)
        return;
    for (int i = head[u]; i != -1; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v != fa) {
            ans = max(ans, getT(v, hea));
            dfs3(v, u, hea);
        }
    }
}
void cul()
{
    dfs(1, -1, 0);
    if (ndep <= m) {
        ans = 0;
        return;
    }
    dfs2(s, -1, 0);
    dfs3(s, -1, s);
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    init();
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    cul();
    cout << ans << endl;
    return 0;
}
