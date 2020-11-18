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
const int maxn = 1e3 + 5;
const double eps = 1e-6;
const double pi = acos(-1.0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int N, L;
bool used[maxn];
int sgn(double x)
{
    if (fabs(x) < eps) return 0;
    if (x > 0) return 1;
    return -1;
}
struct Point {
    double x, y;
    Point() {}
    Point(double x, double y)
        : x(x)
        , y(y)
    {
    }
    Point operator-(const Point& b)
    {
        return Point(x - b.x, y - b.y);
    }
    bool operator<(const Point& p) const
    {
        if (sgn(x - p.x) == 0) return y < p.y;
        return x < p.x;
    }
};
typedef Point Vector;
Point pt[maxn], resPt[maxn];
int pstk;
int stk[maxn << 1];
int dcmp(double x)
{
    return x < -eps ? -1 : x > eps;
}
double cross(Vector a, Vector b)
{
    return a.x * b.y - a.y * b.x;
}
void Andrew(int n, Point* resPt, int& m)
{
    mst(used, false);
    sort(pt + 1, pt + 1 + n);
    pstk = 0;
    stk[++pstk] = 1;
    for (int i = 2; i <= n; i++) {
        while (pstk > 1
            && dcmp(cross(pt[stk[pstk]] - pt[stk[pstk - 1]], pt[i] - pt[stk[pstk]])) <= 0) {
            used[stk[pstk--]] = false;
        }
        used[i] = true;
        stk[++pstk] = i;
    }
    int tmp = pstk;
    for (int i = n - 1; i >= 1; i--) {
        if (used[i]) continue;
        while (pstk > tmp
            && dcmp(cross(pt[stk[pstk]] - pt[stk[pstk - 1]], pt[i] - pt[stk[pstk]])) <= 0) {
            used[stk[pstk--]] = false;
        }
        used[i] = true;
        stk[++pstk] = i;
    }
    m = pstk;
    for (int i = 1; i <= m; i++) {
        resPt[i] = pt[stk[i]];
    }
}
double sqr(double x)
{
    return x * x;
}
double calcDis(double x1, double y1, double x2, double y2)
{
    return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}
int main()
{
    int T;scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&N,&L);
        double x, y;
        for (int i = 1; i <= N; i++) {
            scanf("%lf%lf", &x, &y);
            pt[i].x = x, pt[i].y = y;
        }
        int cnt;
        Andrew(N, resPt, cnt);
        debug(cnt);
        double ans = 0;
        for (int i = 0; i < cnt; i++) {
            ans += calcDis(resPt[i + 1].x, resPt[i + 1].y, resPt[(i + 1) % cnt + 1].x, resPt[(i + 1) % cnt + 1].y);
        }
        ans += 2 * pi * L;
        printf("%.0lf\n", ans);
        if(T) puts("");
    }
    return 0;
}
