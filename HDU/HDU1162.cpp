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
    int id;
    double x;
    double y;
} ns[105];
double sqr(double x)
{
    return x * x;
}
double dist(node na, node nb)
{
    return sqrt(sqr(na.x - nb.x) + sqr(na.y - nb.y));
}
struct edge {
    int u, v;
    double dis;
    bool operator<(const edge& ed) const
    {
        return dis < ed.dis;
    }
};
vector<edge> es;
int pre[105];
inline void init(int n)
{
    for (int i = 0; i <= n; i++) {
        pre[i] = i;
    }
    es.clear();
}
inline int findr(int x)
{
    if (x == pre[x])
        return x;
    return pre[x] = findr(pre[x]);
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        init(n);
        if (n < 2) {
            puts("0.00");
            continue;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%lf %lf", &ns[i].x, &ns[i].y);
            ns[i].id = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                es.push_back({ i, j, dist(ns[i], ns[j]) });
            }
        }
        sort(es.begin(), es.end());
        int sz = es.size();
        double ans = 0;
        for (int i = 0; i < sz; i++) {
            int fu = findr(es[i].u);
            int fv = findr(es[i].v);
            if (fu != fv) {
                ans += es[i].dis;
                pre[fv] = fu;
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
