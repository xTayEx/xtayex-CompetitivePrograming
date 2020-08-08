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
    int T;
    scanf("%d", &T);
    while (T--) {
        ll x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        ll abnd = min(x, y);
        ll bbnd = min(x, z);
        ll cbnd = min(y, z);
        if (max(abnd, bbnd) < x || max(abnd, cbnd) < y || max(bbnd, cbnd) < z) {
            puts("NO");
        } else {
            puts("YES");
            printf("%lld %lld %lld\n", abnd, bbnd, cbnd);
        }
    }
    return 0;
}