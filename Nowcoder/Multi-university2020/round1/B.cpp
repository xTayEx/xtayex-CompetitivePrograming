
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
#define lldebug(x) printf("%s = %lld\n", #x, x)
#define INF 0x3f3f3f3f
#define lowbit(x) (x & (-x))
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int mindiv[maxn];
int w[maxn], dep[maxn], c[maxn];
vector<int> G[maxn];
ll ans;
int n;
int sum(int i)
{
    int s = 0;
    while (i) {
        s += c[i];
        i -= lowbit(i);
    }
    return s;
}
void add(int i, int x)
{
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
}
void get_mindiv(int bnd)
{
    for (int i = 2; i <= bnd; i++) {
        if (!mindiv[i]) {
            for (int j = i; j <= bnd; j += i) {
                if (!mindiv[j]) {
                    mindiv[j] = i;
                }
            }
        }
    }
}
int lcadep[maxn];
int stk[maxn], Top, tot;
void buildVirTree() // 建虚树
{
    tot = n, Top = 1;
    stk[1] = 1;
    for (int i = 2; i <= n; i++) {
        dep[i] = dep[i - 1] + 1;
        int j = i;
        while (j != mindiv[j]) {
            dep[i]++;
            j = j / mindiv[j];
        }
        lcadep[i] = sum(n) - sum(j - 1);
        j = i;
        while (j != 1) {
            add(mindiv[j], 1);
            j = j / mindiv[j];
        }
    }
    for (int i = 2; i <= n; i++) {
        while (Top > 1 && dep[stk[Top - 1]] >= lcadep[i]) {
            G[stk[Top - 1]].emplace_back(stk[Top]);
            G[stk[Top]].emplace_back(stk[Top - 1]);
            Top--;
        }
        if (dep[stk[Top]] != lcadep[i]) {
            dep[++tot] = lcadep[i];
            G[tot].emplace_back(stk[Top]);
            G[stk[Top]].emplace_back(tot);
            stk[Top] = tot;
        }
        stk[++Top] = i;
    }
    while (Top > 1) {
        G[stk[Top - 1]].emplace_back(stk[Top]);
        G[stk[Top]].emplace_back(stk[Top - 1]);
        Top--;
    }
}
void dfs(int u, int fa)
{
    ans += 1LL * w[u] * dep[u];
    int sz = G[u].size();
    for (int i = 0; i < sz; i++) {
        int v = G[u][i];
        if (v == fa)
            continue;
        dfs(v, u);
        w[u] += w[v];
    }
}
void solve(int u, int fa)
{
    int sz = G[u].size();
    for (int i = 0; i < sz; i++) {
        int v = G[u][i];
        if (v == fa)
            continue;
        if ((w[1] - w[v]) - w[v] < 0) {
            ans += ((w[1] - w[v]) - w[v]) * (dep[v] - dep[u]);
            solve(v, u);
        }
    }
}
inline void init()
{
    ans = 0, Top = 0;
    for (int i = 0; i <= tot; i++) {
        mindiv[i] = c[i] = w[i] = dep[i] = lcadep[i] = 0;
        G[i].clear();
    }
}
int main()
{
    while (scanf("%d", &n) != EOF) {
        init();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &w[i]);
        }
        get_mindiv(n);
        buildVirTree();
        dfs(1, 0), solve(1, 0);
        printf("%lld\n", ans);
    }
    return 0;
}
