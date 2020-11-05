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
ll fpow(ll a, ll b)
{
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}
int main()
{
    int T;
    scanf("%d", &T);
    int kase = 0;
    while (T--) {
        ll n, k;
        scanf("%lld%lld", &n, &k);
        printf("Case #%d: ", ++kase);
        if (k == 1 || k >= 30) {
            printf("%lld\n", n);
        } else {
            ll ans = 0;
            int lef = 1, rig = 1;
            for (int i = 1 ;; i++) {
                lef = fpow(i, k);
                rig = fpow(i + 1, k);
                rig--;
                if (lef <= n && n <= rig) {
                    if (lef == n) {
                        ans++;
                    } else {
                        rig = n;
                        ans += 1 + (rig - lef) / i;
                    }
                    break;
                }
                ans += 1 + (rig - lef) / i;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
