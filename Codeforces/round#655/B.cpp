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
#define debug(x) cerr << #x << " = " << x
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll solve(ll x)
{
    vector<ll> vi;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            vi.push_back(i);
            if (i != x / i) {
                vi.push_back(x / i);
            }
        }
    }
    sort(vi.begin(), vi.end());
    int len = vi.size();
    return vi[len - 2];
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n;
        scanf("%lld", &n);
        if (n % 2LL == 0LL) {
            printf("%lld %lld\n", n / 2, n / 2);
        } else {
            ll res = solve(n);
            printf("%lld %lld\n", res, n - res);
        }
    }
    return 0;
}
