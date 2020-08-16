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
vector<int> G[maxn];
char type[maxn];
vector<int> id[maxn];
struct edge {
    int u, v, dis;
    edge(int u, int v, int dis)
        : u(u)
        , v(v)
        , dis(dis)
    {
    }
};
vector<edge> es;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, s, t;
        ll x;
        scanf("%d%d%d%d%lld", &n, &m, &s, &t, &x);
        scanf("%s", type + 1);
        int a, b, d;
        int tot = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", &a, &b, &d);
            es.emplace_back(a, b, d);
        }
        for (int i = 1; i <= n; i++) {
            id[i].clear();
            if (type[i] == 'M') {
                id[i].emplace_back(++tot);
                id[i].emplace_back(++tot);
            } else {
                id[i].emplace_back(++tot);
            }
        }
        int siz;
        for (int i = 1; i <= m; i++) {
            
        }
    }
}
