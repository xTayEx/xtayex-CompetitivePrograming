
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
#define debug printf("debug\n")
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 2e2 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll a[maxn][maxn], sum[maxn], c[maxn], dps[maxn], n, m;
double ans[maxn];
int p[maxn];
struct test {
    double a, b, d;
    bool operator<(const test& g) const
    {
        return d > g.d;
    }
} t[1005];

bool pd(double x)
{
    double cur = 0;
    for (int i = 0; i < m; i++)
        t[i].d = t[i].a - x * t[i].b;
    sort(t, t + m);
    for (int i = 0; i < m; i++)
        if (t[i].d > 0)
            cur += t[i].d;
    return cur > 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &n, &m);
        double res = 0;
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%lld", &a[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum[j] += a[i][j];
            }
            for (int j = 0; j < m; j++) {
                t[j].a = sum[j];
                t[j].b = a[i][j];
            }
            double L = 0, R = 1e10, mid, eps = 1e-8;
            while (fabs(R - L) > eps) {
                mid = (L + R) / 2.0;
                if (pd(mid))
                    L = mid;
                else
                    R = mid;
            }
            res = max(mid, res);
        }
        printf("%.8f\n", res);
    }
    return 0;
}
