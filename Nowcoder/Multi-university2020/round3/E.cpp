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
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll arr[maxn];
ll dp[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &arr[i]);
        }
        ll ans = 0;
        sort(arr + 1, arr + 1 + n);
        for (int i = 1; i <= n; i += 2) {
            ans += (arr[i + 1] - arr[i]);
        }
        dp[0] = 0;
        if (n >= 4)
            dp[4] = arr[4] - arr[1] + arr[3] - arr[2];
        if (n >= 6)
            dp[6] = arr[6] - arr[1] + arr[5] - arr[4] + arr[3] - arr[2];
        if (n >= 8)
            dp[8] = arr[4] - arr[1] + arr[3] - arr[2] + arr[8] - arr[5] + arr[7] - arr[6];
        for (int i = 10; i <= n; i += 2) {
            ll tmp1 = arr[i] - arr[i - 3] + arr[i - 1] - arr[i - 2];
            ll tmp2 = arr[i] - arr[i - 5] + arr[i - 1] - arr[i - 2] + arr[i - 3] - arr[i - 4];
            dp[i] = min(dp[i - 4] + tmp1, dp[i - 6] + tmp2);
        }
        printf("%lld\n", ans + dp[n]);
    }
    return 0;
}
