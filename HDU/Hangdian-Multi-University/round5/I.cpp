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
const int maxn = 1e5 + 5;
const long long mod = 998244353;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll fpow(ll a, ll n, ll p)
{
    ll ret = 1;
    while (n) {
        if (n & 1)
            ret = (ret % mod * a % mod) % mod;
        n >>= 1, a = (a % mod * a % mod) % mod;
    }
    return ret;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n;
        scanf("%lld", &n);
        n %= (mod - 1);
        ll pow2n = fpow(2, n, mod);
        double ans = pow2n + 1 + 2 * (fpow(3, n, mod) / (1.0 * pow2n));
        printf("%lf\n", ans);
    }
    return 0;
}
