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
ll a[maxn][maxn], sum[maxn], c[maxn], dps[maxn];
double ans[maxn];
int p[maxn];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n, m;
        scanf("%lld%lld", &n, &m);
        double res = 0;
        
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
                dps[j] = sum[j];
                c[j] = a[i][j];
                ans[j] = 1.0 * dps[j] / c[j];
                int flag = j;
                for (int k = 0; k < j; k++) {
                    double tmp = 1.0 * (dps[j] + dps[k]) / (c[j] + c[k]);
                    if (tmp > ans[j]) {
                        ans[j] = tmp;
                        flag = k;
                    }
                }
                if (flag != j) {
                    dps[j] += dps[flag];
                    c[j] += c[flag];
                }
                res = max(res, ans[j]);
            }
        }
        printf("%.8f\n", res);
    }
    return 0;
}
/*
8
8 4 5 7 3 6 2 1
10
1 8 2 3 4 5 6 9 10 7*/
