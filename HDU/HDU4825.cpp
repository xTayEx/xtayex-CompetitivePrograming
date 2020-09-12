#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define debug printf("debug\n")
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll a[maxn];
int nxt[maxn * 32][2];
int tot;
inline void init()
{
    tot = 1, mst(nxt, -1);
}
void push(ll val)
{
    int p = 0;
    for (int i = 32; i >= 0; i--) {
        int now = (val >> i) & 1LL;
        if (nxt[p][now] == -1) nxt[p][now] = tot++;
        p = nxt[p][now];
    }
}
ll query(ll val)
{
    int p = 0;
    ll ans = 0;
    for (int i = 32; i >= 0; i--) {
        ll now = (val >> i) & 1LL;
        now ^= 1;
        if (nxt[p][now] != -1) {
            ans = (ans << 1) + now, p = nxt[p][now];
        } else {
            now ^= 1;
            ans = (ans << 1) + now, p = nxt[p][now];
        }
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d", &T);
    int Case = 1;
    while (T--) {
        init();
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        int tmp, cur;
        for (int i = 1; i <= n; i++) {
            push(a[i]);
        }
        int q;
        printf("Case #%d:\n", Case++);
        while (m--) {
            scanf("%d", &q);
            ll ans = query(q);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
