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
//#include <unordered_map>
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e4 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
vector<int> g[maxn];
int f[maxn][3];
void dfs(int u, int fa)
{
    f[u][0] = 1, f[u][1] = INF, f[u][2] = 0;
    if (u == 1) f[u][2] = INF;
    int sz = g[u].size();
    int mininc = INF;
    int sum = 0;
    bool flag = 0;
    int soncnt = 0;
    for (int i = 0; i < sz; i++) {
        int v = g[u][i];
        if (v == fa) continue;
        soncnt++;
        dfs(v, u);
        f[u][0] += min(f[v][0], min(f[v][1], f[v][2]));
        f[u][2] += min(f[v][0], f[v][1]);
        if (f[v][0] < f[v][1]) {
            flag = 1, sum += f[v][0];
        } else {
            sum += f[v][1];
        }
        if (f[v][0] >= f[v][1]) mininc = min(mininc, f[v][0] - f[v][1]);
    }
    if (soncnt == 0) return;
    if (flag)
        f[u][1] = sum;
    else
        f[u][1] = sum + mininc;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a, b;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    int ans = min(f[1][0], min(f[1][1], f[1][2]));
    //debug(f[1][0]), debug(f[1][1]), debug(f[1][2]);
    printf("%d\n", ans);
    return 0;
}
