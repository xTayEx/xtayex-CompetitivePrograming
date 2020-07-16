#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define debug printf("debug\n")
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
#define double long double
const int maxn = 1e5 + 5;
using namespace std;
using pii = pair<double, double>;
typedef long long ll;
typedef unsigned long long ull;
struct point {
    double x;
    double y;
};
point ps[2005];
void getaxi(double x1, double y1, double x2, double y2, double x3, double y3, double& X, double& Y)
{
    double a, b, c, g, e, f;
    e = 2 * (x2 - x1);
    f = 2 * (y2 - y1);
    g = x2 * x2 - x1 * x1 + y2 * y2 - y1 * y1;
    a = 2 * (x3 - x2);
    b = 2 * (y3 - y2);
    c = x3 * x3 - x2 * x2 + y3 * y3 - y2 * y2;
    X = (g * b - c * f) / (e * b - a * f);
    Y = (a * g - c * e) / (a * f - b * e);
}
map<pii, ll> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    double tmpx, tmpy;
    for (int i = 1; i <= n; i++) {
        cin >> tmpx >> tmpy;
        ps[i].x = tmpx;
        ps[i].y = tmpy;
    }
    double X, Y;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        mp.clear();
        for (int j = i + 1; j <= n; j++) {
            if (fabs(ps[i].x * ps[j].y - ps[i].y * ps[j].x) < 1e-10)
                continue;
            getaxi(0.0, 0.0, ps[i].x, ps[i].y, ps[j].x, ps[j].y, X, Y);
            //printf("i = %d, j = %d, X = %Lf, Y = %Lf\n", i, j, X, Y);
            pii pa = make_pair(X, Y);
            mp[pa]++;
            ans = max(ans, mp[pa]);
        }
    }
    cout << ans + 1 << "\n";
    return 0;
}
