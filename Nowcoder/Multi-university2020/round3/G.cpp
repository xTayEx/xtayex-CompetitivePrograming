#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
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
const int maxn = 8e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
vector<int> G[maxn];
list<int> group[maxn];
int pre[maxn];
//int ans[maxn];
unordered_map<int, bool> vis;
inline void init(int n)
{
    for (int i = 0; i < n; i++) {
        pre[i] = i;
        G[i].clear();
        group[i].clear();
        group[i].push_back(i);
    }
    vis.clear();
}
int findr(int x)
{
    if (pre[x] == x)
        return x;
    return pre[x] = findr(pre[x]);
}
void solve(int gid)
{
    int siz = group[gid].size();
    for (int j = 0; j < siz; j++) {
        int now = group[gid].front();
        int sz = G[now].size();
        for (int i = 0; i < sz; i++) {
            int v = G[now][i];
            if (vis[v])
                continue;
            int fnow = findr(now);
            int fv = findr(v);
            if (fnow == fv)
                continue;
            pre[fv] = fnow;
            group[fnow].splice(group[fnow].end(), group[fv]);
        }
        group[gid].pop_front();
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        init(n);
        int u, v;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
        int op;
        scanf("%d", &op);
        while (op--) {
            int que;
            scanf("%d", &que);
            solve(que);
        }
        for (int i = 0; i < n; i++) {
            int ans = findr(i);
            printf("%d%c", ans, i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
