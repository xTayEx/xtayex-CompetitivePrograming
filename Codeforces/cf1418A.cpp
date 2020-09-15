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
ll Ceil(ll a, ll b)
{
    return (a + b - 1) / b;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ll x, y, k;
        cin >> x >> y >> k;
        ll up = k + y * k - 1LL;
        ll down = x - 1LL;
        ll ans = Ceil(up, down) + k;
        printf("%lld\n", ans);
    }
    return 0;
}
