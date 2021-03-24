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
ll x, y;
void solve()
{
    ll ans = 0;
    ll bnd = sqrt(1 + x);
    if (y <= bnd) {
        ans = (y - 1) * y / 2;
    } else {
        ans += (bnd - 1) * bnd / 2;
        ll lef, rig;
        for (lef = bnd + 1; lef <= y; lef = rig + 1) {
            if (x / (lef + 1) == 0) {
                break;
            } else {
                rig = min(y, min(x, x / (x / (lef + 1)) - 1));
            }
            ans += (rig - lef + 1) * (x / (lef + 1));
        }
    }
    printf("%lld\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &x, &y);
        solve();
    }
    return 0;
}
