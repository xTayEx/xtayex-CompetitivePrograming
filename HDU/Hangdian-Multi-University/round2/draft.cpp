
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
const int maxn = 100;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[maxn], b[maxn], c[maxn], d[maxn];
int n, k;
vector<int> v[51];
int sa, sb, sc, sd;
ll ans;
ll ansk[maxn];
void dfs(int u)
{
    if (ansk[u] * 0.9 > 1ll * (sa + 100) * (sb + 100) * (sc + 100) * (sd + 100)) {
        return;
    }
    ansk[u] = max(ansk[u], 1ll * (sa + 100) * (sb + 100) * (sc + 100) * (sd + 100));
    if (u == k + 1) {
        ans = max(ans, 1ll * (sa + 100) * (sb + 100) * (sc + 100) * (sd + 100));
        return;
    }
    if (v[u].size() == 0) {
        dfs(u + 1);
    }
    for (auto i : v[u]) {
        sa += a[i];
        sb += b[i];
        sc += c[i];
        sd += d[i];
        dfs(u + 1);
        sa -= a[i];
        sb -= b[i];
        sc -= c[i];
        sd -= d[i];
    }
}
int cmp(const int& x, const int& y)
{
    return a[x] + b[x] + c[x] + d[x] > a[y] + b[y] + c[y] + d[y];
}
int main()
{
    freopen("J.in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        sa = sb = sc = sd = 0;
        ans = 0;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            int tp;
            scanf("%d%d%d%d%d", &tp, &a[i], &b[i], &c[i], &d[i]);
            v[tp].push_back(i);
        }
        for (int i = 1; i <= k; i++) {
            ansk[i] = 0;
            sort(v[i].begin(), v[i].end(), cmp);
        }
        dfs(1);
        printf("%lld\n", ans);
    }
    return 0;
}
