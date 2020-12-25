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
#define double long double
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll x, ll y)
{
    return y == 0 ? x : gcd(y, x % y);
}
ll a, b;
ll solve(ll rig)
{
    ll delta = a * a - 4 * rig;
    if (delta < 0) {
        return -1;
    } else {
        double x1 = (a * 1.0 + sqrtl(delta)) / 2.0;
        double x2 = (a * 1.0 - sqrtl(delta)) / 2.0;
        double maxix = max(x1, x2);
        double minix = min(x1, x2);
        if (floorl(maxix) == maxix) {
            return (ll)maxix;
        } else if (floorl(minix) == minix) {
            return (ll)minix;
        } else {
            return -1;
        }
    }
}
int main()
{
    while (scanf("%lld%lld", &a, &b) != EOF) {
        ll rig = b * gcd(a, b);
        ll res = solve(rig);
        if (res == -1) {
            puts("No Solution");
        } else {
            ll y = a - res;
            printf("%lld %lld\n", min(y, res), max(y, res));
        }
    }
    return 0;
}
