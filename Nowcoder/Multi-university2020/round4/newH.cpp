#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
bool isnp[N], vis[N];
vector<int> primes;
vector<pii> ans;

void init()
{
    isnp[0] = isnp[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!isnp[i]) {
            primes.emplace_back(i);
        }
        for (int x : primes) {
            if (1LL * x * i >= N)
                break;
            isnp[x * i] = true;
            if (i % x == 0)
                break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    init();
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        ans.clear();
        for (int i = 1; i <= n; ++i)
            vis[i] = 0;
        for (int i = n / 2; i >= 2; --i) {
            if (vis[i])
                continue;
            for (int x : primes) {
                if (1LL * x * i > n)
                    break;
                if (vis[x * i] || vis[i])
                    continue;
                ans.emplace_back(i, x * i);
                vis[i] = vis[x * i] = 1;
            }
        }

        cout << ans.size() << "\n";
        for (auto& p : ans) {
            cout << p.first << ' ' << p.second << '\n';
        }
        cout << flush;
    }
    return 0;
}
