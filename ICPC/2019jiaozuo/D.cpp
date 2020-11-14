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
const double pi = acos(-1);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
double sqr(double x)
{
    return x * x;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        double a, b, r, d;
        scanf("%lf%lf%lf%lf", &a, &b, &r, &d);
        d = d * pi / 180.0;
        double theta = atan(1.0 * b / a);
        double phi = pi - theta;
        double x2 = sqr(a) + sqr(b) + sqr(r) - 2 * (sqrt(sqr(a) + sqr(b))) * r * cos(phi);
        double x = sqrt(x2);
        double ans = x - r;
        double y = atan(1.0 * b / (a + r));
        if (d > y) {
            printf("%.12lf\n", ans);
        } else {
            double ans1 = ;
            printf("%.12lf\n", ans1);
        }
    }
    return 0;
}
