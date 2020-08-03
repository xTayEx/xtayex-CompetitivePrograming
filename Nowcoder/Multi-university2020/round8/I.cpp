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
struct node {
    int a, b;
    bool operator<(const node& nn) const
    {
        if (a != nn.a)
            return a < nn.a;
        return b < nn.b;
    }
};
node ns[maxn];
unordered_map<int, bool> vis;
int main()
{
    int T;
    scanf("%d", &T);
    int kase = 1;
    while (T--) {
        vis.clear();
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &ns[i].a, &ns[i].b);
        }
        sort(ns + 1, ns + 1 + n);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (ns[i].a > ns[i].b)
                swap(ns[i].a, ns[i].b);
            if (!vis[ns[i].a]) {
                vis[ns[i].a] = 1;
                //printf("%d ",ns[i].a);
                ans++;
            } else if (!vis[ns[i].b]) {
                vis[ns[i].b] = 1;
                //printf("%d ",ns[i].b);
                ans++;
            }
        }
        //puts("");
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}
