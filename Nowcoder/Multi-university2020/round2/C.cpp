#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 5;

vector<int> g[N];
vector<int> leaves;
vector<pii> ans;

void dfs(int u, int fa)
{
    bool has_next = false;
    for (int v : g[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
        has_next = true;
    }
    if (!has_next) {
        leaves.push_back(u);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    int tot = leaves.size(), i, j;
    for (i = 0, j = tot - 1; i < j; ++i, --j) {
        ans.emplace_back(leaves[i], leaves[j]);
    }
    if (i == j) {
        ans.emplace_back(1, leaves[i]);
    }
    cout << ans.size() << "\n";
    for (auto& p : ans) {
        cout << p.first << ' ' << p.second << "\n";
    }
    return 0;
}
