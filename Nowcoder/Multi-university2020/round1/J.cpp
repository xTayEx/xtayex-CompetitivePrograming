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
const int bnd = 2e6 + 2;
const ll mod = 998244353;
ll frac[bnd];
inline void init()
{
    frac[0] = frac[1] = 1;
    for (int i = 2; i <= bnd; i++) {
        frac[i] = (frac[i - 1] % mod * i % mod) % mod;
    }
}
ll exgcd(ll a, ll b, ll& x, ll& y)
{
    if (a == 0 && b == 0) {
        return -1;
    }
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
ll inv(ll a, ll n)
{
    ll x, y;
    ll d = exgcd(a, n, x, y);
    if (d == 1)
        return (x % n + n) % n;
    else
        return -1;
}
int main()
{
    init();
    ll n;
    while (scanf("%lld", &n) != EOF) {
        ll f = frac[n];
        ll ff = frac[2 * n + 1];
        ll up = (f % mod * f % mod) % mod;
        ll down = ff % mod;
        ll ans = (up % mod * inv(down, mod) % mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}
