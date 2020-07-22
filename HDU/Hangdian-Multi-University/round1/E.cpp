#include <iostream>

using namespace std;
using ll = long long;

const int N = 1e5 + 5;
const ll MOD = 1e9 + 9;
const ll SQRT5 = 383008016;
const ll A = 691504013;
const ll B = 308495997;

#define debug              \
    do {                   \
        cout << "debug\n"; \
    } while (0);
ll fac[N], a[N], b[N];

inline ll quick_pow(ll a, ll b)
{
    ll ret = 1;
    a %= MOD;
    while (b) {
        if (b & 1)
            ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

inline ll inv(ll x)
{
    return quick_pow(x, MOD - 2);
}

inline ll combine(ll r, ll k)
{
    return fac[k] * inv(fac[k - r] * fac[r]) % MOD;
}

void init()
{
    fac[0] = 1;
    for (int i = 1; i < N; ++i)
        fac[i] = fac[i - 1] * i % MOD;
}

void init(ll c, int k)
{
    ll aa = quick_pow(A, c);
    ll bb = quick_pow(B, c);
    a[0] = b[0] = 1;
    for (int i = 1; i <= k; ++i) {
        a[i] = a[i - 1] * aa % MOD;
        b[i] = b[i - 1] * bb % MOD;
    }
}

ll solve(ll n, ll k)
{
    ll ans = 0, tmp, s = 1;
    for (int r = 0; r <= k; r++) {
        ll t = a[k - r] * b[r] % MOD;
        ll c = combine(r, k);

        if (t == 1)
            tmp = n % MOD;
        else
            tmp = t * (quick_pow(t, n) - 1) % MOD * inv(t - 1) % MOD;

        ans = (ans + s * c * tmp) % MOD;

        s *= -1;
    }
    ans = ans * quick_pow(inv(SQRT5), k) % MOD;
    return (ans + MOD) % MOD;
}

int main()
{
    init();
    //debug
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll t, n, c, k;
    cin >> t;
    while (t--) {
        cin >> n >> c >> k;
        init(c, k);
        //debug
        cout << solve(n, k) << endl;
    }
    return 0;
}
