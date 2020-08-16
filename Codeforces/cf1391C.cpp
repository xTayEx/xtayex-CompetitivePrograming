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
#define idebug(x) printf("%s = %d\n", #x, x)
#define ddebug(x) printf("%s = %lf\n", #x, x)
#define lldebug(x) printf("%s = %lld\n", #x, x)
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e6 + 5;
const long long mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll f[maxn];
inline void init(ll n)
{
    f[1] = 1;
    for (ll i = 2; i <= n; i++) {
        f[i] = (f[i - 1] % mod * (1LL * i) % mod) % mod;
    }
}
ll fpow(ll a, ll b)
{
    ll ret = 1;
    while (b) {
        if (b & 1)
            ret = (ret % mod * a % mod) % mod;
        a = (a % mod * a % mod) % mod;
        b >>= 1;
    }
    return ret;
}
int main()
{
    ll n;
    scanf("%lld", &n);
    init(n);
    ll ans = (f[n] - fpow(2, n - 1)) % mod;
    while (ans < 0)
        ans = (ans + mod) % mod;
    printf("%lld\n", ans);
    return 0;
}
