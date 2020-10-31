#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e7 + 7;
vector<int> prime;
int ck[maxn];
void shai()
{
    ck[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!ck[i]) {
            prime.push_back(i);
        }
        for (int j = 0; j < (int)prime.size() && 1ll * i * prime[j] < maxn; j++) {
            ck[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
int a[maxn];
int cnt[maxn];
int dp[maxn];
int main()
{
    shai();
    //printf("%d\n", prime.size());
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0;
    int Cnt = 0;
    for (int i = 1; i < maxn; i++) {
        dp[i] = max(dp[i], cnt[i]);
        for (int j = 0; j < (int)prime.size() && 1ll * prime[j] * i <= 1e7; j++) {
            dp[prime[j] * i] = max(dp[prime[j] * i], dp[i] + cnt[prime[j] * i]);
            Cnt++;
        }
        ans = max(ans, dp[i]);
    }
    cout << Cnt << "\n";
    cout << ans << "\n";
}
