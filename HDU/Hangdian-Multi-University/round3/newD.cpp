
#include <bits/stdc++.h>
using namespace std;
int n, p, ans;
int sum[100005] = { 0 };
int main()
{
    int t;
    cin >> t;
    while (t--) {
        ans = 0;
        map<int, int> mp;
        scanf("%d%d", &n, &p);
        mp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int temp;
            scanf("%d", &temp);
            sum[i] = (sum[i - 1] + temp) % p;
            if (mp.count(sum[i])) {
                ans++;
                mp.clear();
                sum[i] = 0;
                mp[0] = 1;
            } else {
                mp[sum[i]] = 1;
            }
        }
        cout << ans << endl;
    }
}
