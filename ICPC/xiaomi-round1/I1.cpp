#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
const int N = 1e3 + 5;

int n, m;
char s[N][N];
char dp[N][N];
char vis[N][N];

bool dfs(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > m) return false;
    if (dp[i][j] != -1) return dp[i][j];

    if (vis[i][j]) return dp[i][j] = true;
    vis[i][j] = true;

    if (s[i][j] == 'A')
        return dp[i][j] = dfs(i, j - 1);
    if (s[i][j] == 'W')
        return dp[i][j] = dfs(i - 1, j);
    if (s[i][j] == 'S')
        return dp[i][j] = dfs(i + 1, j);
    if (s[i][j] == 'D')
        return dp[i][j] = dfs(i, j + 1);
    return 0;
}

int main()
{
    //freopen("./I.in", "r", stdin);
    //freopen("./I1.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(dp, -1, sizeof(dp));
        memset(vis, 0, sizeof(vis));

        for (int i = 1; i <= n; ++i)
            scanf("%s", s[i] + 1);

        int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                ans += !dfs(i, j);

        printf("%d\n", ans);
    }

    return 0;
}
