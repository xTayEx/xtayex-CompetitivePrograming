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
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int w;
    ll ans = 0;
    for (w = 3; m - w + 2 > 0; w += 2)
        ans += (m - w + 2) * (n + 1);
    for (w = 3; n - w + 2 > 0; w += 2)
        ans += (n - w + 2) * (m + 1);
    ll tmp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tmp += min(i, n - i) * min(j, m - j);
        }
    }
    ans += tmp * 2;
    printf("%lld\n", ans);
    return 0;
}
