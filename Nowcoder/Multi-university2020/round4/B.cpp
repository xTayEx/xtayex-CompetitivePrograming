#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5, MOD = 1e9 + 7;
bool isnp[N];
vector<int> primes;
int minpf[N];

void init()
{
    isnp[0] = isnp[1] = 1;
    minpf[1] = 1;
    memset(minpf, 0x7f, sizeof(minpf));
    for (int i = 2; i < N; ++i) {
        if (!isnp[i]) {
            primes.emplace_back(i);
            minpf[i] = i;
        }

        for (int x : primes) {
            if (1LL * x * i >= N)
                break;
            isnp[x * i] = true;
            minpf[x * i] = min(minpf[x * i], x);
            if (i % x == 0)
                break;
        }
    }
}

ll f(ll c, ll x)
{
    if (x == 1)
        return 1;
    return c * f(c, x / minpf[x]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    init();
    ll t, n, c;
    cin >> t;
    while (t--) {
        cin >> n >> c;
        cout << f(c, n) << "\n";
    }
    return 0;
}
