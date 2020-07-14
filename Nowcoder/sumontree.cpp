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
//#define debug printf("debug\n")
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
#define int long long
const int maxn = 1e5 + 5;
const int mod = 23333;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n, m;
struct edge {
    int nxt;
    int to;
};
int head[maxn];
int fa[maxn];
edge es[maxn << 1];
int tot;
int cnt;
int depth[maxn];
int newwei[maxn];
int W[maxn];
int sz[maxn];
int maxson[maxn];
int Top[maxn];
inline void init()
{
    mst(head, -1);
    tot = cnt = 0;
    mst(maxson, 0);
}
inline void add(int u, int v)
{
    es[++tot].to = v;
    es[tot].nxt = head[u];
    head[u] = tot;
}
void dfs1(int now, int f, int dep)
{
    depth[now] = dep;
    fa[now] = f;
    sz[now] = 1;
    int maxi = -1;
    int v;
    for (int i = head[now]; i != -1; i = es[i].nxt) {
        v = es[i].to;
        if (v == f)
            continue;
        dfs1(v, now, dep + 1);
        sz[now] += sz[v];
        if (sz[v] > maxi) {
            maxi = sz[v];
            maxson[now] = v;
        }
    }
}
int id[maxn];
void dfs2(int now, int topf)
{
    id[now] = ++cnt;
    newwei[id[now]] = W[now];
    Top[now] = topf;
    if (maxson[now] == 0)
        return;
    dfs2(maxson[now], topf);
    int v;
    for (int i = head[now]; i != -1; i = es[i].nxt) {
        v = es[i].to;
        if (v == fa[now] || v == maxson[now]) {
            continue;
        }
        dfs2(v, v);
    }
    return;
}

// ------------segment tree----------
int p;
int sum1[maxn << 2];
int sum2[maxn << 2];
int lazy[maxn << 2];
inline void pushup(int rt)
{
    sum1[rt] = (sum1[rt << 1] + sum1[rt << 1 | 1]) % mod;
    sum2[rt] = (sum2[rt << 1] + sum2[rt << 1 | 1]) % mod;
}
void build(int lef, int rig, int rt)
{
    //sum1[rt] = sum2[rt] = 0;
    lazy[rt] = 0;
    if (lef == rig) {
        sum1[rt] = newwei[lef] % mod;
        sum2[rt] = (sum1[rt] % mod * sum1[rt] % mod) % mod;
        return;
    }
    int mid = (lef + rig) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
void pushdown(int rt, int len)
{
    if (lazy[rt]) {
        lazy[rt] %= mod;
        int add = lazy[rt];
        lazy[rt << 1] = (lazy[rt << 1] % mod + add % mod) % mod;
        lazy[rt << 1 | 1] = (lazy[rt << 1 | 1] % mod + add % mod) % mod;
        sum2[rt << 1] = (sum2[rt << 1] + add % mod * add % mod * (len - (len >> 1)) + 2 * add % mod * sum1[rt << 1] % mod) % mod;
        sum2[rt << 1 | 1] = (sum2[rt << 1 | 1] + add % mod * add % mod * (len >> 1) + 2 * add % mod * sum1[rt << 1 | 1] % mod) % mod;
        sum1[rt << 1] = (sum1[rt << 1] + add % mod * (len - (len >> 1)) % mod) % mod;
        sum1[rt << 1 | 1] = (sum1[rt << 1 | 1] + add % mod * (len >> 1) % mod) % mod;
        lazy[rt] = 0;
    }
}
void update_range(int L, int R, int todo, int lef, int rig, int rt)
{
    if (L <= lef && rig <= R) {
        lazy[rt] = (todo + lazy[rt]) % mod;
        sum2[rt] = (sum2[rt] % mod + (todo % mod * todo % mod) * (rig - lef + 1) + 2 * sum1[rt] % mod * todo % mod) % mod;
        sum1[rt] = (sum1[rt] % mod + (rig - lef + 1) * todo % mod) % mod;
        return;
    }
    int mid = (lef + rig) / 2;
    pushdown(rt, rig - lef + 1);
    //------------以后都用这种写法!--------------
    if (L > mid)
        update_range(L, R, todo, rson);
    else if (R <= mid)
        update_range(L, R, todo, lson);
    else {
        update_range(L, R, todo, lson);
        update_range(L, R, todo, rson);
    }
    //------------以后都用这种写法!--------------
    pushup(rt);
}
int query(int L, int R, int lef, int rig, int rt)
{
    if (L <= lef && rig <= R) {
        return sum2[rt] % mod;
    }
    int mid = lef + (rig - lef) / 2;
    pushdown(rt, rig - lef + 1);
    //int ret = 0;
    //------------以后都用这种写法!--------------
    if (L > mid)
        return query(L, R, rson) % mod;
    if (R <= mid)
        return query(L, R, lson) % mod;
    else {
        ll ans = query(L, R, lson) % mod;
        ans = (ans + query(L, R, rson) % mod) % mod;
        return ans;
    }
    //------------以后都用这种写法!--------------
    //return ret % mod;
}
// ---------------op on tree------------------
inline void son_udpate(int x, int z)
{
    z %= mod;
    update_range(id[x], id[x] + sz[x] - 1, z, 1, n, 1);
}
inline int son_query(int x)
{
    int ret = query(id[x], id[x] + sz[x] - 1, 1, n, 1);
    ret = ret % mod;
    return ret;
}
int32_t main()
{
    init();
    scanf("%lld", &n);
    int q;
    scanf("%lld", &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &W[i]);
    }
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        scanf("%lld %lld", &u, &v);
        add(u, v);
        add(v, u);
    }
    //debug;
    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, n, 1);
    int x;
    int y;
    //printf("%lld\n", y);
    while (q--) {
        //debug;
        int op;
        scanf("%lld", &op);
        if (op == 1) {
            scanf("%lld %lld", &x, &y);
            son_udpate(x, y);
        } else if (op == 2) {
            scanf("%lld", &x);
            int que = son_query(x) % mod;
            printf("%lld\n", que);
        }
    }
    return 0;
}
