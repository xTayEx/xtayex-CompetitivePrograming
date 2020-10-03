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
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
#define lld I64d
const int maxn = 5e4 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
vector<int> g[maxn];
ll dp[maxn][505];
int n, k;
ll ans;
void dfs(int u, int fa)
{
    int sz = g[u].size();
    dp[u][0] = 1;
    for (int i = 0; i < sz; i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u);
        for (int j = 0; j < k; j++) {
            ans = ans + dp[u][j] * dp[v][k - 1 - j];
        }
        for (int j = 1; j <= k; j++) {
            dp[u][j] += dp[v][j - 1];
        }
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    int u, v;
    ans = 0;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}
