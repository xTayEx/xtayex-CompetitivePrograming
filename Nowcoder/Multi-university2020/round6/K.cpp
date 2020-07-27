#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
unordered_map<int, int> mp;
int a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] > k)
                flag = false;
        }

        // left;
        int cnt, l, r;
        mp.clear(), cnt = 0, r = 0;
        for (int i = 1; i <= n && flag; ++i) {
            if (mp[a[i]]++ == 0)
                cnt++;
            if (mp[a[i]] >= 2) {
                r = i - 1;
                break;
            }
        }
        mp.clear(), cnt = 0, l = 0;
        for (int i = n; i > r && flag; --i) {
            if (mp[a[i]]++ == 0)
                cnt++;
            if (mp[a[i]] >= 2) {
                l = i + 1;
                break;
            }
        }
        mp.clear(), cnt = 0;
        if ((l - r - 1) % k)
            flag = false;
        for (int i = r + 1; i < l && flag; ++i) {
            if (mp[a[i]]++ == 0)
                cnt++;
            if (i - r > k && --mp[a[i - k + 1]] == 0)
                cnt--;
            if (i - r >= k && cnt != k)
                flag = false;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
