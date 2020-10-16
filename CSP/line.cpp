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
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e3 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double eps = 1e-5;
int sgn(double x)
{
    if (fabs(x) < eps) return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}
struct point {
    double x, y;
    point() {}
    point(double x, double y)
        : x(x)
        , y(y)
    {
    }
    point operator-(const point& b) const
    {
        return point(x - b.x, y - b.y);
    }
    double operator^(const point& b) const
    {
        return x * b.y - y * b.x;
    }
};
point ps[maxn];
char tt[maxn];
struct line {
    point s, e;
    line(point _s, point _e)
    {
        s = _s, e = _e;
    }
    line(double a, double b, double c)
    {
        if (sgn(a) == 0) {
            s = point(0, -c / b);
            e = point(1, -c / b);
        } else if (sgn(b) == 0) {
            s = point(-c / a, 0);
            e = point(-c / a, 1);
        } else {
            s = point(0, -c / b);
            e = point(1, (-c - a) / b);
        }
    }
    int relation(point p)
    {
        int c = sgn((p - s) ^ (e - s));
        if (c < 0)
            return 1;
        else if (c > 0)
            return 2;
        else
            return 3;
    }
};
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    double x, y;
    char t[2];
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf%s", &x, &y, t);
        ps[i] = { x, y };
        tt[i] = t[0];
    }
    double c, a, b;
    for (int i = 1; i <= m; i++) {
        int typea = -1;
        int typeb = -1;
        scanf("%lf%lf%lf", &c, &a, &b);
        line l(a, b, c);
        bool flag = 1;
        for (int i = 0; i < n; i++) {
            const point& p = ps[i];
            int ret = l.relation(p);
            if (tt[i] == 'A') {
                if (typea == -1) {
                    typea = ret;
                } else {
                    if (typea != ret) {
                        flag = 0;
                        break;
                    }
                }
            } else if (tt[i] == 'B') {
                if (typeb == -1) {
                    typeb = ret;
                } else {
                    if (typeb != ret) {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (!flag)
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}
