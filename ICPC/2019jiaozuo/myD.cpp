#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
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
const double pi = acos(-1.0);
const double degToRadContant = pi / 180.0;
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
        d = d * degToRadContant;
        double bnd = atan(b * 1.0 / (a * 1.0 + r * 1.0));
        double ans;
        if (d > bnd) {
            ans = sqrt(sqr(b) + sqr(a + r)) - r;
            printf("%.12lf\n", ans);
        } else {
            double delta = d - bnd;
            double l = sqrt(sqr(b) + sqr(a + r));
            ans = l * cos(delta) - r;
            printf("%.12lf\n", ans);
        }
    }
    return 0;
}
