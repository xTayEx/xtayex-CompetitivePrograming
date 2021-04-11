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

ll mul(ll x, ll y, ll m)
{
    ll ans = x * y - (ll)((long double)x * y / m + 0.5) * m;
    return ans < 0 ? ans + m : ans;
}

inline ll fpow(ll a, ll b, ll p)
{
    ll ret = 1;
    while (b) {
        if (b & 1) ret = mul(ret, a, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return ret;
}

namespace miller_rabin {
    inline bool is_prime(ll x)
    {
        if (x == 2 || x == 3 || x == 7 || x == 61 || x == 24251) return 1;
        if (x % 2 == 0 || x < 2 || x == 46856248255981LL) return 0;
        ll s = 0;
        ll t = x - 1;
        while (!(t & 1)) ++s, t >>= 1;
        for (ll a : { 2, 61, 3, 7, 11, 13, 233, 2333 }) {
            ll b = fpow(a, t, x);
            for (int i = 0; i < s; i++) {
                ll k = mul(b, b, x);
                if (k == 1 && b != 1 && b != x - 1) return 0;
                b = k;
            }
            if (b != 1) return 0;
        }
        return 1;
    }
}

int main()
{
    bool flag = 1;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= 10000; i++) {
        ll tmp;
        scanf("%lld", &tmp);
        if (miller_rabin::is_prime(tmp)) {
            cnt2++;
        } else {
            cnt1++;
        }
    }
    if (cnt1 > cnt2)
        puts("Rilly");
    else
        puts("Northy");
    return 0;
}
