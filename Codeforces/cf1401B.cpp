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
ll a[5], b[5];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld", &a[0], &a[1], &a[2]);
        scanf("%lld%lld%lld", &b[0], &b[1], &b[2]);
        ll ans = 0;

        ll tmp = min(a[2], b[1]);
        a[2] -= tmp, b[1] -= tmp;
        ans += tmp * 2;

        tmp = min(a[0], b[2]);
        a[0] -= tmp, b[2] -= tmp;

        tmp = min(a[1], b[0]);
        a[1] -= tmp, b[0] -= tmp;

        tmp = min(a[1], b[2]);
        a[1] -= tmp, b[2] -= tmp;
        ans -= tmp * 2;
        printf("%lld\n", ans);
    }
    return 0;
}
