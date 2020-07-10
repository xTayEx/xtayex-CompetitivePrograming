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
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int pre[maxn];
inline void init(int n)
{
    for (int i = 0; i <= n; i++) {
        pre[i] = i;
    }
}
inline int findr(int x)
{
    if (pre[x] == x)
        return x;
    return pre[x] = findr(pre[x]);
}
inline void merge(int x, int y)
{
    int fx = findr(x);
    int fy = findr(y);
    if (fx != fy) {
        pre[fy] = fx;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        init(n);
        int x, y;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            merge(x, y);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (pre[i] == i)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
