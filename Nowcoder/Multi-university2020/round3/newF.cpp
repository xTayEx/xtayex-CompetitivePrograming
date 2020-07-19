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
const int maxn = 2e6 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
vector<int> vec;
bool isnprime[maxn + 10];
void init()
{
    mst(isnprime, 0);
    vec.clear();
    int bnd = sqrt(maxn);
    for (int i = 2; i <= bnd; i++) {
        if (!isnprime[i]) {
            for (int j = i + i; j <= maxn; j += i) {
                isnprime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= maxn; i++) {
        if (!isnprime[i]) {
            vec.push_back(i);
        }
    }
}
ll gcd(ll a, ll b)
{
    return !b ? a : gcd(b, a % b);
}
ll exgcd(ll a, ll b, ll& x, ll& y)
{
    if (a == 0 && b == 0)
        return -1;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main()
{
    init();
    int len = vec.size();
    int T;
    scanf("%d", &T);
    while (T--) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ll g = gcd(a, b);
        if (g > 1) {
            printf("%lld %lld %lld %lld\n", ((a / g) + 1), b / g, 1LL, b / g);
        } else if (g == 1) {
            ll tmpb = b;
            ll fact = 1LL;
            for (int i = 0; vec[i] * vec[i] <= tmpb && i < len; i++) {
                if (tmpb % vec[i] == 0) {
                    while (tmpb % vec[i] == 0) {
                        fact *= vec[i];
                        tmpb /= vec[i];
                    }
                    break;
                }
            }
            if (tmpb != 1 && fact != 1) {
                ll d = fact;
                ll f = tmpb;
                ll c, e;
                exgcd(f, d, c, e);
                e = -e;
                while (e < 0 || c < 0)
                    e += f, c += d;
                ll mul = a / gcd(f, d);
                e *= mul, c *= mul;
                printf("%lld %lld %lld %lld\n", c, d, e, f);
            } else {
                puts("-1 -1 -1 -1");
            }
        }
    }
    return 0;
}
