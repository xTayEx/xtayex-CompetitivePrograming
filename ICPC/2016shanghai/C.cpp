#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
int a[maxn], vis[maxn];
int n;
int s2(int l)
{
    int r = l;
    while (vis[a[l]] && r < n) {
        l++;
        r++;
    }
    int ans = 0;
    if (r < n) ans = 1, vis[a[l]]++;
    while (l < n && r < n) {
        while (r + 1 < n && !vis[a[r + 1]]) {
            r++;
            vis[a[r]]++;
            ans = max(ans, r - l + 1);
        }
        if (l < r) {
            vis[a[l]]--;
            l++;
        } else {
            vis[a[l]]--;
            l++;
            r++;
            while (vis[a[l]] && r < n) {
                l++;
                r++;
            }
            if (l < n)
                vis[a[l]]++;
        }
    }
    return ans;
}
int solve()
{
    memset(vis, 0, sizeof(vis));
    int l = 0, r = 0;
    vis[a[l]]++;
    int ans = 1;
    ans = max(ans, r - l + 1 + s2(2));
    while (l < n && r < n) {
        while (r + 1 < n && !vis[a[r + 1]]) {
            r++;
            vis[a[r]]++;
            ans = max(ans, r - l + 1 + s2(r + 2));
        }
        if (l < r) {
            vis[a[l]]--;
            l++;
            ans = max(ans, r - l + 1 + s2(r + 2));
        } else {
            vis[a[l]]--;
            l++;
            r++;
            vis[a[l]]++;
            ans = max(ans, r - l + 1 + s2(r + 2));
        }
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int T = 0;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        a[n] = 0;
        cout << "Case #" << ++T << ": ";
        cout << solve() << endl;
    }
    return 0;
}
