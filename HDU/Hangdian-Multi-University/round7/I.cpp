#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5 + 5;
int ans[N];

bool solve(int x, int y, int n)
{
    if (n == 0 && x == 0)
        return true;

    if (x <= 0 || y <= 0 || x > n || y > n || x * y < n)
        return false;

    int now = n;
    for (int i = n - y + 1; i <= n; ++i)
        ans[i] = now--;

    return solve(x - 1, min(now + 2 - x, y), n - y);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        if (solve(x, y, n)) {
            puts("YES");
            for (int i = 1; i <= n; ++i)
                printf("%d%c", ans[i], " \n"[i == n]);
        } else {
            puts("NO");
        }
    }
    return 0;
}
