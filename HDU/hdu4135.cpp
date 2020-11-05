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
ll prime[maxn];
ll getprime(ll n)
{
    ll cnt = 0;
    for (int i = 2; i * i * 1LL <= n; i++) {
        if (n % (1LL * i) == 0) {
            prime[cnt++] = i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1LL) prime[cnt++] = n;
    return cnt;
}
ll que[maxn];
ll solve(ll x, ll cnt)
{
    int p = 0;
    que[p++] = -1;
    for (int i = 0; i < cnt; i++) {
        int bnd = p;
        for (int j = 0; j < bnd; j++) {
            que[p++] = -1 * que[j] * prime[i];
        }
    }
    ll sum = 0;
    for (int i = 1; i < p; i++) {
        sum += x / que[i];
    }
    return sum;
}
int main()
{
    int T;
    scanf("%d", &T);
    int kase = 0;
    while (T--) {
        ll a, b, n;
        scanf("%lld%lld%lld", &a, &b, &n);
        ll cnt = getprime(n);
        ll ans = (b - solve(b, cnt)) - ((a - 1) - solve(a - 1, cnt));
        printf("Case #%d: ", ++kase);
        printf("%lld\n", ans);
    }
    return 0;
}
