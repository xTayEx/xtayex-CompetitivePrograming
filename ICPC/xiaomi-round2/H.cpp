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
#define debug(x) cerr << "\033[01;31m" << #x << " = " << x << "\033[0m" \
                      << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct node {
    int w, v;
    bool operator<(const node& nn) const
    {
        return (1.0 * v) / (1.0 * w) > (1.0 * nn.v) / (1.0 * nn.w);
    }
} ns[maxn];
ll f[maxn];
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        mst(f, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &ns[i].w, &ns[i].v);
        }
        sort(ns + 1, ns + 1 + n);
        ll ans = 0;
        int p = 1;
        while (p <= n && m >= 500) {
            m -= ns[p].w;
            ans += ns[p].v * 1LL;
            p++;
        }
        for (int i = p; i <= n; i++) {
            for (int j = m; j >= ns[i].w; j--) {
                f[j] = max(f[j], f[j - ns[i].w] + ns[i].v);
            }
        }
        ans += f[m];
        printf("%lld\n", ans);
    }
    return 0;
}
