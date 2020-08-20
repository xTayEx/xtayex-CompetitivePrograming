#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define debug(x) cerr << #x << " " << x << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll t[maxn], x[maxn];
vector<int> G[maxn];
unordered_map<ll, int> lvis;
inline void addedge(int u, int v)
{
    G[u].emplace_back(v);
    G[v].emplace_back(u);
}
bool used[maxn];
int bnd, dis;
int dx[maxn], dy[maxn], cx[maxn], cy[maxn];
int tot;
bool bfs()
{
    queue<int> que;
    dis = INF;
    mst(dx, -1), mst(dy, -1);
    for (int i = 1; i <= bnd; i++) {
        if (cx[i] == -1) {
            que.push(i);
            dx[i] = 0;
        }
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        if (dx[u] > dis) break;
        for (auto& v : G[u]) {
            if (dy[v] == -1) {
                dy[v] = dx[u] + 1;
                if (cy[v] == -1)
                    dis = dy[v];
                else
                    dx[cy[v]] = dy[v] + 1, que.push(cy[v]);
            }
        }
    }
    return dis != INF;
}
int dfs(int u)
{
    for (auto v : G[u]) {
        if (!used[v] && dy[v] == dx[u] + 1) {
            used[v] = 1;
            if (cy[v] != -1 && dy[v] == dis) continue;
            if (cy[v] == -1 || dfs(cy[v])) {
                cy[v] = u, cx[u] = v;
                return 1;
            }
        }
    }
    return 0;
}
int hopcroft_karp()
{
    int res = 0;
    mst(cx, -1), mst(cy, -1);
    while (bfs()) {
        mst(used, 0);
        for (int i = 1; i <= bnd; i++) {
            if (cx[i] == -1) {
                res += dfs(i);
            }
        }
    }
    return res;
}
inline void init(int n)
{
    for (int i = 0; i <= 2 * n; i++) {
        G[i].clear();
    }
}
vector<int> vi;
int getid(int x)
{
    int ret = distance(vi.begin(), lower_bound(vi.begin(), vi.end(), x)) + 1;
    return ret;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        vi.clear();
        int n;
        scanf("%d", &n);
        init(n);
        tot = 0, bnd = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld%lld", &t[i], &x[i]);
            ll tmp1 = x[i] - t[i];
            ll tmp2 = x[i] + t[i];
            vi.push_back(tmp1), vi.push_back(tmp2);
        }
        sort(vi.begin(), vi.end());
        vi.erase(unique(vi.begin(), vi.end()), vi.end());
        bnd = distance(vi.begin(), vi.end());
        for (int i = 1; i <= n; i++) {
            ll tmp1 = x[i] - t[i];
            ll tmp2 = x[i] + t[i];
            int id1 = getid(tmp1);
            int id2 = getid(tmp2);
            G[id1].emplace_back(id2);
        }
        int ans = hopcroft_karp();
        printf("%d\n", ans);
    }
    return 0;
}
