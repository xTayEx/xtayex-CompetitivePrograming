#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int a[N], m, ans;

unordered_map<int, int> cnt;

void dfs(int i, int tot = 0)
{
    ans = max(ans, tot);

    if (i == m)
        return;

    for (int t = 2; t <= 7; ++t) {
        int nxt = lower_bound(a + i, a + m, a[i] * t) - a;
        if (nxt == m || a[nxt] != a[i] * t) continue;
        dfs(nxt, tot + cnt[a[nxt]]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    a[n] = 1;
    sort(a, a + n + 1);
    m = unique(a, a + n + 1) - a;
    dfs(0);

    cout << ans + cnt[1] << endl;
}
