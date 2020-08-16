#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
unordered_map<string, int> mp;
ll mod = 1e9 + 7;
int a[maxn];
int dp1[maxn], dp2[maxn];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        mp.clear();
        int cnt = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            if (mp.find(s) == mp.end()) {
                mp[s] = cnt++;
            }
            a[i] = mp[s];
        }
        dp1[1] = a[1] == a[2] ? 0 : 1;
        dp2[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp1[i] = ((a[i] == a[i + 1] ? 0 : 1) * (dp2[i - 1] + dp1[i - 2])) % mod;
            dp2[i] = (dp2[i - 1] + dp1[i - 2]) % mod;
        }
        ll ans = (dp1[n - 1] + dp2[n]) % mod;
        cout << ans << endl;
    }
}
