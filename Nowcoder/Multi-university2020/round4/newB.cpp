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
const int maxn = 1e6 + 5;
const long long mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
bool isnp[maxn];
vector<ll> prime;
ll mini[maxn];
inline void init()
{
    isnp[0] = isnp[1] = 1;
    mst(mini, INF);
    mini[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!isnp[i]) {
            prime.emplace_back(1LL * i);
            mini[i] = 1LL * i;
        }
        int sz = prime.size();
        for (int j = 0; j < sz; j++) {
            if (1LL * prime[j] * i >= maxn) {
                break;
            }
            isnp[prime[j] * i] = 1, mini[prime[j] * i] = min(mini[prime[j] * i], prime[j]);
            if (i % prime[j] == 0) break;
        }
    }
}
ll calc(ll x, ll c)
{
    return x == 1 ? 1 : (c * calc(x / mini[x], c)) % mod;
}
int main()
{
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n, c;
        scanf("%lld%lld", &n, &c);
        ll ans = calc(n, c);
        ans %= mod;
        printf("%lld\n", ans);
    }
    return 0;
}
