#include <iostream>
#include <stdio.h>
#define INF 10000000
using namespace std;
int c[105], v[105];
int dp[10005]; //dp[i],表示在价值i下的最小重量
int main()
{
    //freopen("1.txt","r",stdin);

    int w, n;
    int i, j;
    int ans;
    while (cin >> n >> w) {
        ans = 0;
        for (i = 0; i < 10000; i++)
            dp[i] = INF;
        dp[0] = 0;
        for (i = 0; i < n; i++)
            cin >> v[i] >> c[i];
        for (i = 0; i < n; i++)
            for (j = 10000; j >= c[i]; j--) {
                dp[j] = min(dp[j - c[i]] + v[i], dp[j]);
            }
        for (i = 0; i < 10000; i++)
            if (dp[i] <= w && ans < i)
                ans = i;

        cout << ans << endl;
    }
    return 0;
}
