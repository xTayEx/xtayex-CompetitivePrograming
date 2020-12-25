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
const int mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll fpow(ll a, ll b)
{
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret % mod * a % mod) % mod;
        a = (a % mod * a % mod) % mod;
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
        ll n, m, k;
        scanf("%lld%lld%lld", &n, &m, &k);
        ll ans = fpow(k, n * m) % mod;
        for (int i = 2; i <= k; i++) {
            ans = (ans + n % mod * m % mod * fpow(i - 1, n + m - 2) % mod * fpow(k, (n - 1) * (m - 1)) % mod) % mod;
        }
        ans %= mod;
        printf("Case #%d: %lld\n", ++kase, ans);
    }
    return 0;
}
