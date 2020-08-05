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
const int maxn = 6e6 + 5;
const long long mod = 998244353;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll exgcd(ll a, ll b, ll& x, ll& y)
{
    if (a == 0 && b == 0)
        return -1;
    if (b == 0) {
        x = 1, y = 0;
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
ll ans[maxn];
ll Inv[maxn];
int main()
{
    int T;
    //freopen("A.in","r",stdin);
    scanf("%d", &T);
    Inv[1] = 1;
    for (int i = 2; i < maxn; i++) {
        Inv[i] = (mod - mod / i) * 1LL * Inv[mod % i] % mod;
    }
    for (int i = 1; i < maxn; i++) {
        ans[i] = (ans[i - 1] + (Inv[i] % mod * Inv[i] % mod)) % mod;
    }
    for (int i = 1; i < maxn; i++) {
        ans[i] = (ans[i] % mod * Inv[i] % mod) % mod;
    }
    while (T--) {
        ll n;
        scanf("%lld", &n);
        printf("%lld\n", (ans[n] * 3LL) % mod);
    }
    return 0;
}
