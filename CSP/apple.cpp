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
    int n, m;
    scanf("%d%d", &n, &m);
    int t, k, p;
    t = k = 0;
    int maxi = -1;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        int tot;
        scanf("%d", &tot);
        for (int j = 1; j <= m; j++) {
            int tmp;
            scanf("%d", &tmp);
            tot += tmp, sum -= tmp;
        }
        t += tot;
        if (sum > maxi) {
            maxi = sum, k = i;
        }
    }
    p = maxi;
    printf("%d %d %d\n", t, k, p);
    return 0;
}
