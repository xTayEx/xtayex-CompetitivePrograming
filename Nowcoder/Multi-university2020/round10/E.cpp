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
#define idebug(x) printf("%s = %d\n", #x, x)
#define ddebug(x) printf("%s = %lf\n", #x, x)
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll a[maxn];
bool sovle(ll bnd, int n)
{
    ll tot = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] > bnd) {
            tot += (a[i] - bnd);
        } else {
            tot -= (bnd - a[i]);
            tot = max(tot, 0LL);
        }
    }
    return tot != 0;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        ll lef = 1, rig = 1e9 + 1;
        while (lef < rig) {
            ll mid = lef + (rig - lef) / 2;
            if (sovle(mid, n)) {
                lef = mid + 1;
            } else {
                rig = mid;
            }
        }
        ll ans = lef;
        printf("%lld\n", ans);
    }
    return 0;
}
