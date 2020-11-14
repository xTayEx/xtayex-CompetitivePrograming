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
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        double a, b, r, d;
        scanf("%lf%lf%lf%lf", &a, &b, &r, &d);
        d = d / 180.0 * acos(-1);
        double l1 = sqrt((a + r) * (a + r) + b * b);
        double x = atan(b * 1.0 / (a + r));
        if (x <= d) {
            printf("%.12f\n", l1 - r);
        } else {
            double xx = x - d;
            double l2 = l1 * cos(xx);
            printf("%.12f\n", l2 - r);
        }
    }
}
