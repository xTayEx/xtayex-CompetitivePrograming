#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e3 + 5;

int n, m;
ll A[N][N], B[N][N];

inline int lowbit(int x) { return x & -x; }

inline void add(int x, int y, int val)
{
    if (x == 0 || y == 0) return;
    for (int xx = x; xx <= n; xx += lowbit(xx))
        for (int yy = y; yy <= m; yy += lowbit(yy))
            B[xx][yy] += val;
}

inline void add(int x, int y, int u, int v, int val)
{
    add(x, y, val);
    add(u + 1, y, -val);
    add(x, v + 1, -val);
    add(u + 1, v + 1, val);
}

inline ll sum(int x, int y)
{
    ll ans = 0;
    for (int xx = x; xx; xx -= lowbit(xx))
        for (int yy = y; yy; yy -= lowbit(yy))
            ans += B[xx][yy];
    return ans;
}

void debug()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cout << sum(i, j) << " \n"[j == m];
}

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> n >> m >> a >> b;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> A[i][j];
                B[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                add(i, j, A[i][j] - A[i - 1][j] - A[i][j - 1] + A[i - 1][j - 1]);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i + a - 1 <= n && j + b - 1 <= m) {
                    int tmp = sum(i, j);
                    if (tmp) add(i, j, i + a - 1, j + b - 1, -tmp);
                }
            }
        }

        bool flag = true;
        for (int i = 1; i <= n && flag; ++i)
            for (int j = 1; j <= m && flag; ++j)
                if (sum(i, j) != 0) flag = false;

        if (flag)
            cout << "^_^\n";
        else
            cout << "QAQ\n";
    }
    return 0;
}
