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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1000000009;
ll fib[maxn];
inline void init(int n)
{
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}
ll fpow(ll a, ll n, ll mod)
{
    ll ret = 1;
    while (n) {
        if (n & 1)
            ret = ret * a % mod;
        a = (a % mod * a % mod) % mod;
        n >>= 1;
    }
    return ret;
}
int main()
{
    init(maxn);
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n, c, k;
        scanf("%lld %lld %lld", &n, &c, &k);
        ll ans = 0;
        for (ll i = 1LL; i <= n; i++) {
            ans = (ans % mod + fpow(fib[i * c], k, mod) % mod) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
