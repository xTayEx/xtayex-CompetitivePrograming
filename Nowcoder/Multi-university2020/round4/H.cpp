#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

vector<int> a, b;
bool vis[N];

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);

    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i <= n; ++i)
            vis[i] = 0;
        for (int i = 2; i <= n; ++i) {
            if (2 * i > n)
                break;
            if (vis[i])
                continue;
            a.emplace_back(i);
            b.emplace_back(2 * i);
            vis[i] = vis[2 * i] = true;
        }
        cout << a.size() << endl;
        for (int i = 0; i < (int)a.size(); ++i) {
            cout << a[i] << ' ' << b[i] << "\n";
        }
    }
    return 0;
}
