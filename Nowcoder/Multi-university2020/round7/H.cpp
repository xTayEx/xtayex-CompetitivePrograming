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
const long long mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll N, K;
inline ll solve(ll x)
{
    ll i = 1;
    ll j;
    ll ans = 0;
    for (i = 1; i <= x && i <= K; i = j + 1) {
        j = min(x / (x / i), K);
        ans = (ans + (j - i + 1) * (x / i) % mod) % mod;
    }
    return ans;
}
int main()
{
    scanf("%lld %lld", &N, &K);
    ll ans = solve(N) % mod;
    ans = (ans % mod + solve(N - 1) % mod) % mod;
    ans = (ans + K - N) % mod;
    printf("%lld\n", ans);
    return 0;
}
