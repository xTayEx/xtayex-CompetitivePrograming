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
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ll l, r, m;
        scanf("%lld%lld%lld", &l, &r, &m);
        ll lef = l - r, rig = r - l;
        for (ll i = l; i <= r; i++) {
            ll tmp = m % i;
            if (tmp <= rig && m >= i) {
                ll ans = m % i;
                printf("%lld %lld %lld\n", i, ans + l, l);
                break;
            }
            if (m % i - i >= lef) {
                ll ans = m % i - i;
                printf("%lld %lld %lld\n", i, ans + r, r);
                break;
            }
        }
    }
    return 0;
}
