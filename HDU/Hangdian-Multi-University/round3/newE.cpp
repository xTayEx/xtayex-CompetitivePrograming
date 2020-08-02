
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
ll mod = 1e9 + 7;
int fa[maxn], p[maxn];
int find(int u)
{
    if (u != fa[u]) {
        fa[u] = find(fa[u]);
    }
    return fa[u];
}
ll trT = 0;
int one[maxn], two[maxn];
ll so = 0, tw = 0;
ll total = 0;
ll c2(int x)
{
    return 1ll * x * (x - 1) / 2;
}
ll solve(int x)
{
    ll ans = 0;
    ans = (1ll * one[x] * (c2(tw - two[x]) - (total - c2(two[x])))) % mod;
    return ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        memset(one, 0, sizeof(one));
        memset(two, 0, sizeof(two));
        so = tw = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            if (p[i] == 1) {
                one[i]++;
                so++;
            } else {
                two[i]++;
                tw++;
            }
            fa[i] = i;
        }
        trT = (1ll * tw * (tw - 1) * (tw - 2) / 6) % mod;
        total = 0;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans = (ans + solve(i)) % mod;
        ans=(ans+trT)%mod;
        printf("%lld\n", ans);
        for (int i = 1; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            int pa = find(a), pb = find(b);
            ll tmp = 0;
            tmp = (tmp % mod + two[pa] % mod * two[pb] % mod * (tw - two[pa] - two[pb]) % mod) % mod;
            //printf("tmp = %lld\n",tmp);
            tmp = (tmp % mod + one[pa] % mod * two[pb] % mod * (tw - two[pa] - two[pb]) % mod) % mod;
            //printf("tmp = %lld\n",tmp);
            tmp = (tmp % mod + two[pa] % mod * one[pb] % mod * (tw - two[pa] - two[pb]) % mod) % mod;
            tmp = (tmp % mod + two[pa] % mod * two[pb] % mod * (so - one[pa] - one[pb]) % mod) % mod;
            //printf("tmp = %lld\n",tmp);
            if (pa != pb) {
                fa[pa] = pb;
                two[pb] += two[pa], one[pb] += one[pa];
            }
            //printf("%lld\n",ans);
            ans = (ans - tmp + mod) % mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
