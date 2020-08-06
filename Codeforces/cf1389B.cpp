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
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[maxn], dp[6][maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k, z;
        scanf("%d %d %d", &n, &k, &z);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        dp[0][0] = a[1];
        for (int i = 0; i <= z; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i][j - 1];
                dp[i][j] += a[1 + j - 2 * i];
                if (i > 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[1 + j - 2 * i]);
            }
        }
        int ans = 0;
        for (int i = 0; i <= z; i++) {
            ans = max(ans, dp[i][k]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
