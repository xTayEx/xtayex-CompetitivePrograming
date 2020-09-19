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
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 2e7 + 5;
const long long mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll f[maxn];
ll inv[maxn];
inline void init()
{
    f[1] = 500000004, f[0] = 1LL, inv[0] = 1LL;
    for (int i = 1; i < maxn; i++) {
        inv[i] = (inv[i - 1] % mod * 500000004LL) % mod;
    }
    for (int i = 1; i < maxn; i++) {
        inv[i] = (inv[i - 1] % mod * inv[i]) % mod;
    }
    ll pow2 = 1, tmp=1;
    for (int i = 1; i < maxn; i++) {
        pow2 = (pow2 * 2LL) % mod;
        tmp = (pow2 - 1) * tmp % mod;
        f[i] = (tmp * inv[i]) % mod;
    }
    for (int i = 2; i < maxn; i++) {
        f[i] = f[i] ^ f[i - 1];
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    init();
    while (T--) {
        ll n;
        scanf("%lld", &n);
        ll ans = f[n];
        printf("%lld\n", ans);
    }
    return 0;
}
