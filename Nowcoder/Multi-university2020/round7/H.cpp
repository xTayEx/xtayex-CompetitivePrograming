#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

ll solve(ll n, ll k)
{
    if (n == 1)
        return n % MOD;
    if (n == 2)
        return 2 * n % MOD;
    if (k > n)
        return (solve(n, n) + k - n) % MOD;
    ll ans = (2 * n + k - 2) % MOD;

    for (ll l = 3, r; l <= k; l = r + 1) {
        if (n < l)
            break;
        r = min(k, n / (n / l));
        ans = (ans + (r - l + 1) * (n / l)) % MOD;
    }
    for (ll l = 3, r; l <= k; l = r + 1) {
        if (n - 1 < l)
            break;
        r = min(k, (n - 1) / ((n - 1) / l));
        ans = (ans + (r - l + 1) * ((n - 1) / l)) % MOD;
    }
    return ans;
}

int main()
{
    ll n, k;
    scanf("%lld%lld", &n, &k);
    printf("%lld\n", solve(n, k));
    return 0;
}
