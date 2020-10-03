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
const int maxn = 2e3 + 5;
const int mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[maxn];
vector<int> g[maxn];
int d, n;
ll dfs(int u, int fa, int rt)
{
    ll ans = 1;
    int sz = g[u].size();
    for (int i = 0; i < sz; i++) {
        int v = g[u][i];
        if (fa == v) continue;
        if (((a[rt] < a[v]) || (a[rt] == a[v] && rt > v)) && a[v] - a[rt] <= d) {
            ll tmp = dfs(v, u, rt);
            ans = (ans * (tmp + 1) % mod) % mod;
        }
    }
    return ans;
}
int main()
{
    scanf("%d%d", &d, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll Ans = 0;
    for (int i = 1; i <= n; i++) {
        Ans = (Ans + dfs(i, 0, i) % mod) % mod;
    }
    printf("%lld\n", Ans);
    return 0;
}
