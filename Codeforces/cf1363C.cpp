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
const int maxn = 2e3 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int deg[maxn];
inline void init(int n)
{
    for (int i = 0; i <= n; i++) {
        deg[i] = 0;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, x;
        scanf("%d %d", &n, &x);
        init(n);
        int u, v;
        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d", &u, &v);
            deg[u]++;
            deg[v]++;
        }
        if (deg[x] <= 1) {
            puts("Ayush");
        } else {
            if (n & 1)
                puts("Ashish");
            else
                puts("Ayush");
        }
        //printf("sz[4] = %d, sz[8] = %d, sz[10] = %d, sz[9] = %d\n",sz[4],sz[8],sz[9],sz[10]);
    }
    return 0;
}
