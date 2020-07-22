#include <iostream>
using namespace std;
#define ll long long
ll mod = 998244353;
ll mul(ll n, ll k)
{
    ll ans = 1;
    while (k) {
        if (k & 1) {
            ans = ans * n % mod;
        }
        n = n * n % mod;
        k >>= 1;
    }
    return ans % mod;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if (n >= 4)
            printf("%lld\n", 1LL * 26 * 25 * 24);
        else
            printf("%lld\n", mul(26, n));
    }
    return 0;
}
