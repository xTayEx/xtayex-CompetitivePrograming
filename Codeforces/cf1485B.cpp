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
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll a[maxn];
ll incr[maxn], decr[maxn];
ll inc_sum[maxn], dec_sum[maxn];
int main()
{
    int n, q, k;
    scanf("%d%d%d", &n, &q, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    a[0] = 0LL, a[n + 1] = k + 1LL;
    for (int i = 1; i <= n; i++) {
        incr[i] = a[i + 1] - a[i] - 1;
        decr[i] = a[i] - a[i - 1] - 1;
    }
    for (int i = 1; i <= n; i++) {
        inc_sum[i] = inc_sum[i - 1] + incr[i];
        dec_sum[i] = dec_sum[i - 1] + decr[i];
    }
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        ll ans = (inc_sum[r - 1] - inc_sum[l]) + (dec_sum[r - 1] - dec_sum[l]) + (a[l] - 1) + (k - a[r]) + incr[l] + decr[r];
        printf("%lld\n", ans);
    }
    return 0;
}
