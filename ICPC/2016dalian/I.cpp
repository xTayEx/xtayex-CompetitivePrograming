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
const double pi = acos(-1.0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    int n;
    double dis;
    while (scanf("%d%lf", &n, &dis) != EOF) {
        double ans = 0;
        for (int i = 0; i < n; i++) {
            double theta;
            scanf("%lf", &theta);
            theta *= pi / 180.0;
            ans += dis * dis * cos(theta / 2) * sin(theta / 2);
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}
