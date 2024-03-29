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
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int dp[maxn][2];
int a[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        dp[1][0] = a[1], dp[1][1] = INF;
        dp[2][0] = a[1] + a[2], dp[2][1] = dp[1][0];
        for (int i = 3; i <= n; i++) {
            dp[i][0] = min(dp[i - 1][1] + a[i], dp[i - 2][1] + a[i - 1] + a[i]);
            dp[i][1] = min(dp[i - 1][0], dp[i - 2][0]);
        }
        int ans = min(dp[n][0], dp[n][1]);
        printf("%d\n", ans);
    }
    return 0;
}
