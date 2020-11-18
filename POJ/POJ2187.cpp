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
//#include <unordered_map>
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define debug(x) cerr << "\033[01;31m" << #x << " = " << x << "\033[0m" \
                      << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 5e4 + 5;
const double eps = 1e-8;
const double pi = acos(-1.0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
bool used[maxn];
struct Point {
    int x, y;
    Point() {}
    Point(int x, int y)
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
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};
typedef Point Vector;
Point pt[maxn], resPt[maxn];
int pstk;
int stk[maxn << 1];
int cross(Vector a, Vector b)
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
            && cross(pt[stk[pstk]] - pt[stk[pstk - 1]], pt[i] - pt[stk[pstk]]) <= 0) {
            used[stk[pstk--]] = false;
        }
        used[i] = true;
        stk[++pstk] = i;
    }
    int tmp = pstk;
    for (int i = n - 1; i >= 1; i--) {
        if (used[i]) continue;
        while (pstk > tmp
            && cross(pt[stk[pstk]] - pt[stk[pstk - 1]], pt[i] - pt[stk[pstk]]) <= 0) {
            used[stk[pstk--]] = false;
        }
        used[i] = true;
        stk[++pstk] = i;
    }
    m = pstk;
    for (int i = 1; i <= m; i++) {
        resPt[i] = pt[stk[i]];
    }
    //debug(m);
}
int sqr(int x)
{
    return x * x;
}
int calcDis(Point p1, Point p2)
{
    int x1 = p1.x, y1 = p1.y;
    int x2 = p2.x, y2 = p2.y;
    return sqr(x1 - x2) + sqr(y1 - y2);
}
int rotateCalipers(int n, int m)
{
    int ret = 0;
    if (n == 3) {
        ret = max(max(calcDis(pt[1], pt[2]), calcDis(pt[1], pt[3])), calcDis(pt[2], pt[3]));
    } else {
        int j = 3;
        for (int i = 1; i <= m; i++) {
            while (abs(cross(resPt[i] - resPt[i + 1], resPt[j] - resPt[i + 1]))
                < abs(cross(resPt[i] - resPt[i + 1], resPt[j + 1] - resPt[i + 1]))) {
                j++;
                if (j >= m) j = 1;
            }
            ret = max(ret, calcDis(resPt[i], resPt[j]));
        }
    }
    return ret;
}
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        pt[i].x = x, pt[i].y = y;
    }
    if (N == 2) {
        printf("%d\n",calcDis(pt[1], pt[2]));
    } else {
        int m;
        Andrew(N, resPt, m);
        int ans = rotateCalipers(N, m);
        printf("%d\n", ans);
    }
    return 0;
}
