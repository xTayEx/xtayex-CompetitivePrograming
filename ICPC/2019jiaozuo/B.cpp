#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e4;

ll ceil_sqrt(ll x)
{
    ll y = sqrt(x - 1);
    while (y * y < x) ++y;
    return y;
}

ll solve(ll a, ll b, ll c)
{
    ll det = ceil_sqrt(b * b - 4 * a * c);
    ll ans = (2 * a - 1 + det - b) / 2 * a;
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll ha, hb, aa, ab;
        cin >> ha >> hb >> aa >> ab;

        //A first
        ll t = solve(1, 1, -2 * ha);
        ll t2 = solve(1, 2 * t + 1, -2 * hb);
        if (t2 <= 0) {
            t2 = 1;
        }
        ll ans1 = t * aa + (t + t2) * ab;

        //B first
        ll t3 = solve(1, 1, -2 * hb);
        ll t4 = solve(1, 2 * t3 + 1, -2 * ha);
        if (t4 <= 0) {
            t4 = 1;
        }
        ll ans2 = t3 * ab + (t3 + t4) * aa;
        if (ans1 <= ans2) {
            cout << ans1 << " ";
            for (int i = 0; i < t; i++) {
                cout << "A";
            }
            for (int i = 0; i < t2; i++) {
                cout << "B";
            }
        } else {
            cout << ans2 << " ";
            for (int i = 0; i < t3; i++) {
                cout << "B";
            }
            for (int i = 0; i < t4; i++) {
                cout << "A";
            }
        }
        cout << endl;
    }
}
