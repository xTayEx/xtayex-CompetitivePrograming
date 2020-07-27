
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using ll = long long;
const int N = 5e3 + 5;
int p[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll n, k;
    cin >> n >> k;
    if (n % 2 == 0) {
        if (k != n / 2) {
            cout << "-1\n";
            return 0;
        }
        int tot = 0;
        for (int i = 1, j = n - 1; i < j; ++i, --j) {
            p[++tot] = i;
            p[++tot] = j;
        }
        p[++tot] = k;
        p[++tot] = n;
        for (int i = 1; i <= n; ++i)
            cout << p[i] << " \n"[i == n];
    } else {
        if (k != 0) {
            cout << "-1\n";
            return 0;
        }
        int tot = 0;
        for (int i = 1, j = n - 1; i < j; ++i, --j) {
            p[++tot] = i;
            p[++tot] = j;
        }
        p[++tot] = n;
        for (int i = 1; i <= n; ++i)
            cout << p[i] << " \n"[i == n];
    }
    return 0;
}
