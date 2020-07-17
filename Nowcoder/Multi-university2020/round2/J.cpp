#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, k;
vector<int> c[maxn];
int vis[maxn];
int a[maxn], d[maxn];
int ans[maxn];
int tot = 0;
void dfs(int u, int fa)
{
    vis[u] = 1;
    c[tot].push_back(u);
    if (a[u] != fa) {
        dfs(a[u], fa);
    }
}
void solve(int t)
{
    int siz = c[t].size();
    int p = k % siz;
    int q = 0;
    for (int i = 0; i < siz; i++) {
        if (1LL * i * p % siz == 1) {
            q = i;
        }
    }
    for (int i = 0; i < siz; i++) {
        ans[c[t][i]] = c[t][(i + q) % siz];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, i);
            tot++;
        }
    }
    //int t = 0;
    for (int i = 0; i < tot; i++) {
        solve(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
