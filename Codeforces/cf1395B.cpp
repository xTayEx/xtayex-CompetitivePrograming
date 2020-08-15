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
#define idebug(x) printf("%s = %d\n", #x, x)
#define ddebug(x) printf("%s = %lf\n", #x, x)
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    printf("%d %d\n", x, y);
    for (int i = x + 1; i <= n; i++) {
        printf("%d %d\n", i, y);
    }
    for (int i = x - 1; i >= 1; i--) {
        printf("%d %d\n", i, y);
    }
    bool sw = 1;
    for (int j = y - 1; j >= 1; j--) {
        if (sw) {
            for (int i = 1; i <= n; i++) {
                printf("%d %d\n", i, j);
            }
        } else {
            for (int i = n; i >= 1; i--) {
                printf("%d %d\n", i, j);
            }
        }
        sw ^= 1;
    }
    sw ^= 1;
    for (int j = y + 1; j <= m; j++) {
        if (sw) {
            for (int i = n; i >= 1; i--) {
                printf("%d %d\n", i, j);
            }
        } else {
            for (int i = 1; i <= n; i++) {
                printf("%d %d\n", i, j);
            }
        }
        sw ^= 1;
    }
    return 0;
}
