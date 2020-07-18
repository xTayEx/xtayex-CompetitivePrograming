
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
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[maxn];
ll d[maxn], t;
ll dis[maxn];
ll solve()
{
    dis[0] = d[1];
    dis[1] = d[1];
    dis[2] = dis[1] + d[2];
    for (int i = 3; i <= t - 2; i++) {
        dis[i] = min(dis[i - 1], dis[i - 2]) + d[i];
    }
    dis[t - 1] = min(dis[t - 2], dis[t - 3]) + d[t - 1];
    return dis[t - 1];
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        ll ans1 = 0;
        t = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (i % 2 == 1) {
                ans1 += a[i];
            } else {
                ans1 -= a[i];
                if (i != 0) {
                    d[t++] = a[i] - a[i - 1];
                }
            }
        }
        cout << 2 * ans1 + 2 * solve() << '\n';
    }
    return 0;
}
