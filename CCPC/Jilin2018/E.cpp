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
#define debug(x) cerr << "\033[01;31m" << #x << " = " << x << "\033[0m" \
                      << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
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
struct Point3 {
    double x, y, z;
    Point3(double _x = 0, double _y = 0, double _z = 0)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    void input()
    {
        scanf("%lf%lf%lf", &x, &y, &z);
    }
    bool operator==(const Point3& b) const
    {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0 && sgn(z - b.z) == 0;
    }
};
struct Line3 {
    Point3 s, e;
    Line3() {}
    Line3(Point3 _s, Point3 _e)
    {
        s = _s;
        e = _e;
    }
    bool operator==(const Line3& v)
    {
        return (s == v.s && e == v.e);
    }
};
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        double r, h;
        scanf("%lf%lf", &r, &h);
        double x0, y0, z0;
        scanf("%lf%lf%lf", &x0, &y0, &z0);
        double vx, vy, vz;
        scanf("%lf%lf%lf", &vx, &vy, &vz);
    }
}
