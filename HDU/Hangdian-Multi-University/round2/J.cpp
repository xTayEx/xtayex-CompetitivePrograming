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
const int maxn = 105;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int W[maxn][4];
int n, k;
vector<int> v[51];
int sa, sb, sc, sd;
ll ans;
ll ansk[maxn];
ll sum[52][4];
void dfs(int u)
{
    ans = max(ans, 1LL * (sa + 100) * (sb + 100) * (sc + 100) * (sd + 100));
    if ((1LL * (sa + sum[u][0] + 100) * (sb + sum[u][1] + 100) * (sc + sum[u][2] + 100) * (sd + sum[u][3] + 100)) < ans) {
        return;
    }
    if (u == k + 1) {
        return;
    }
    if (v[u].size() == 0) {
        dfs(u + 1);
    }
    for (auto i : v[u]) {
        sa += W[i][0];
        sb += W[i][1];
        sc += W[i][2];
        sd += W[i][3];
        dfs(u + 1);
        sa -= W[i][0];
        sb -= W[i][1];
        sc -= W[i][2];
        sd -= W[i][3];
    }
}
int cmp(const int& x, const int& y)
{
    return W[x][0] + W[x][1] + W[x][2] + W[x][3] > W[y][0] + W[y][1] + W[y][2] + W[y][3];
}
ll maxi[52][4];
int main()
{
    //freopen("J.in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        sa = sb = sc = sd = 0;
        ans = 0;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= k; i++) {
            v[i].clear();
        }
        for (int i = 0; i < n; i++) {
            int tp;
            scanf("%d%d%d%d%d", &tp, &W[i][0], &W[i][1], &W[i][2], &W[i][3]);
            v[tp].push_back(i);
            for (int j = 0; j < 4; j++) {
                maxi[tp][j] = max(1LL * W[i][j], maxi[tp][j]);
            }
        }
        for (int i = k; i >= 1; i--) {
            for (int j = 0; j < 4; j++) {
                sum[i][j] = sum[i + 1][j] + maxi[i][j];
            }
        }
        dfs(1);
        printf("%lld\n", ans);
    }
    return 0;
}
