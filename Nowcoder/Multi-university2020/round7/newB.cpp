
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
vector<int> ans;

int main()
{
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        if (n == m) {
            printf("%d\n", m);
            for (int i = 0; i < m; ++i)
                printf("%d%c", m, " \n"[i == m - 1]);
            continue;
        }
        if (n < m)
            swap(n, m);
        int s = n - m;

        ans.clear();

        for (int i = 0; i < m; ++i)
            ans.emplace_back(m);

        int left = n * m - m * m;

        if (s > m) {
            for (int i = 0; i < m; ++i)
                ans.emplace_back(m), left -= m;
            s = s - m;
        }

        for (int i = 0; i < (m / s) * s; ++i)
            ans.emplace_back(s), left -= s;

        while (left) {
            ans.emplace_back(m % s);
            left -= m % s;
        }

        ll siz = ans.size();
        printf("%lld\n", siz);
        for (int i = 0; i < siz; ++i) {
            printf("%d%c", ans[i], " \n"[i == (int)siz - 1]);
        }
    }
    return 0;
}
