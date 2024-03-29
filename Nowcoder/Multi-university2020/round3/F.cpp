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
ll gcd(ll a, ll b)
{
    return !b ? a : gcd(b, a % b);
}
bool isnprime[maxn + 20];
vector<int> vec;
void getprime()
{
    mst(isnprime, 0);
    int bnd = (int)sqrt(maxn);
    bnd++;
    for (int i = 2; i <= bnd; i++) {
        if (!isnprime[i]) {
            for (int j = i * i; j <= maxn; j += i) {
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
int main()
{
    int T;
    scanf("%d", &T);
    vec.clear();
    getprime();
    int tot = vec.size();
    while (T--) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ll g = gcd(a, b);
        if (g > 1) {
            printf("%lld %lld %lld %lld\n", ((a / g) + 1), b / g, 1LL, b / g);
        } else if (g == 1) {
            ll tmpb = b;
            ll res = 1LL;
            for (int i = 0; 1LL * vec[i] * vec[i] <= tmpb && i < tot; i++) {
                if (tmpb % vec[i] == 0) {
                    while (tmpb % vec[i] == 0) {
                        tmpb /= vec[i];
                        res *= vec[i];
                    }
                    break;
                }
            }
            if (tmpb > 1 && res != 1) {
                ll d = res;
                ll f = tmpb;
                ll c, e;
                exgcd(f, d, c, e);
                //printf("c = %lld, e = %lld\n",c,e);
                c *= a;
                e *= a;
                if (c > 0 && e < 0) {
                    printf("%lld %lld %lld %lld\n", c, d, -e, f);
                } else {
                    printf("%lld %lld %lld %lld\n", e, f, -c, d);
                }
            } else {
                puts("-1 -1 -1 -1");
            }
        }
    }
    return 0;
}
