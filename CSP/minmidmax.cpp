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
#define INF 0x3f3f3f3f3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll a[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    ll mini = INF, maxi = -INF;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        mini = min(mini, a[i]), maxi = max(maxi, a[i]);
    }
    if (n & 1) {
        printf("%lld %lld %lld\n", maxi, a[(n + 1) / 2], mini);
    } else {
        ll midval = (a[n / 2] + a[n / 2 + 1]);
        if (midval % 2LL == 0)
            printf("%lld %lld %lld\n", maxi, midval / 2LL, mini);
        else
            printf("%lld %.1lf %lld\n", maxi, (midval * 1.0) / 2.0, mini);
    }
    return 0;
}
