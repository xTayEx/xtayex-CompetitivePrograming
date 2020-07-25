#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 407;
const int M = 4e5 + 7;
int r, c, m, B, a[N][N], tot, cnt[N * N], ans, out[M];
struct Query {
    int x, y, xx, yy, id;
    bool operator<(Query& b)
    {
        return x / B == b.x / B ? (y / B == b.y / B ? (xx / B == b.xx / B ? yy < b.yy : xx < b.xx) : y < b.y) : x < b.x;
    }
} q[M];
void add(int x)
{
    if (!cnt[x])
        ans++;
    ++cnt[x];
}
void del(int x)
{
    --cnt[x];
    if (!cnt[x])
        ans--;
}
int getS(string& s, int& cnt2)
{
    char a = s[0];
    int cnt = 0;
    cnt2 = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (a != s[i]) {
            break;
        } else
            cnt++;
    }
    for (int i = cnt; i < (int)s.size(); i++) {
        if (s[cnt] != s[i]) {
            break;
        } else
            cnt2++;
    }
    if (s[0] == 'U' || s[0] == 'D') {
        swap(cnt, cnt2);
    }
    return cnt;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int i, j, x = 1, y = 1, xx = 0, yy = 0;
        cin >> r >> c >> m;
        memset(cnt, 0, sizeof(cnt));
        B = pow(r * c, 0.5) / pow(m, 0.25) + 1.0;
        for (i = 1; i <= r; ++i) {
            for (j = 1; j <= c; ++j) {
                cin >> a[i][j];
            }
        }
        for (i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            string s;
            cin >> s;
            int d2;
            int d = getS(s, d2);
            if (s[0] == 'R' || s[d] == 'R') {
                q[i].x = a + 1;
                q[i].xx = a + d;
            } else {
                q[i].x = a - d + 1;
                q[i].xx = a;
            }
            if (s[0] == 'U' || s[d] == 'U') {
                q[i].y = b + 1;
                q[i].yy = b + d2;
            } else {
                q[i].y = b - d2 + 1;
                q[i].yy = b;
            }
            q[i].id = i;
        }
        sort(q, q + m);
        ans = 0;
        for (i = 0; i < m; ++i) {
            while (x > q[i].x) {
                --x;
                for (j = y; j <= yy; ++j) {
                    add(a[x][j]);
                }
            }
            while (xx < q[i].xx) {
                ++xx;
                for (j = y; j <= yy; ++j) {
                    add(a[xx][j]);
                }
            }
            while (y > q[i].y) {
                --y;
                for (j = x; j <= xx; ++j) {
                    add(a[j][y]);
                }
            }
            while (yy < q[i].yy) {
                ++yy;
                for (j = x; j <= xx; ++j) {
                    add(a[j][yy]);
                }
            }
            while (x < q[i].x) {
                for (j = y; j <= yy; ++j) {
                    del(a[x][j]);
                }
                ++x;
            }
            while (xx > q[i].xx) {
                for (j = y; j <= yy; ++j) {
                    del(a[xx][j]);
                }
                --xx;
            }
            while (y < q[i].y) {
                for (j = x; j <= xx; ++j) {
                    del(a[j][y]);
                }
                ++y;
            }
            while (yy > q[i].yy) {
                for (j = x; j <= xx; ++j) {
                    del(a[j][yy]);
                }
                --yy;
            }
            out[q[i].id] = ans;
        }
        for (i = 0; i < m; ++i) {
            cout << out[i] << "\n";
        }
    }
    return 0;
}
