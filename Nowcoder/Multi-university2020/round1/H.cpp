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
const int maxn = 100 + 5;
const int maxm = 200 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct edge {
    int to;
    int nxt;
    int cap;
    int flow;
    int cost;
} es[maxm];
int head[maxn];
int tol;
int pre[maxn], dis[maxn];
bool vis[maxn];
ll ansarr[maxm];
int N; // 节点总个数, 节点从0~N-1
int M;
inline void init(int n)
{
    N = n;
    tol = 0;
    mst(head, -1);
}
inline void addedge(int u, int v, int cap, int cost)
{
    es[tol].to = v;
    es[tol].cap = cap;
    es[tol].cost = cost;
    es[tol].flow = 0;
    es[tol].nxt = head[u];
    head[u] = tol++;

    es[tol].to = u;
    es[tol].cap = 0;
    es[tol].cost = -cost;
    es[tol].flow = 0;
    es[tol].nxt = head[v];
    head[v] = tol++;
}
bool spfa(int s, int t)
{
    queue<int> que;
    for (int i = 0; i < N; i++) {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    que.push(s);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for (int i = head[u]; i != -1; i = es[i].nxt) {
            int v = es[i].to;
            if (es[i].cap > es[i].flow && dis[v] > dis[u] + es[i].cost) {
                dis[v] = dis[u] + es[i].cost;
                pre[v] = i;
                if (!vis[v]) {
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }
    if (pre[t] == -1)
        return false;
    else
        return true;
}
ll mcmf(int s, int t, ll& cost)
{
    ll flow = 0;
    cost = 0;
    while (spfa(s, t)) {
        ll Min = INF;
        for (int i = pre[t]; i != -1; i = pre[es[i ^ 1].to]) {
            if (Min > es[i].cap - es[i].flow) {
                Min = es[i].cap - es[i].flow;
            }
        }
        for (int i = pre[t]; i != -1; i = pre[es[i ^ 1].to]) {
            es[i].flow += Min;
            es[i ^ 1].flow -= Min;
            cost += es[i].cost * Min;
        }
        flow += Min;
        ansarr[(int)flow] = cost;
    }
    return flow;
}
inline int read()
{
    char ch;
    int x = 0;
    int sign = 1;
    do {
        ch = getchar();
        if (ch == '-')
            sign = -1;
    } while (ch > '9' || ch < '0');
    while ('0' <= ch && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = getchar();
    }
    return x * sign;
}
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
//inline void Swap(ll& a,ll& b)
//{
//ll tmp=a;
//a=b;b=tmp;
//}
int main()
{
    while (scanf("%d %d", &N, &M) != EOF) {
        init(N);
        int ai, bi, ci;
        for (int i = 0; i < M; i++) {
            ai = read();
            bi = read();
            ci = read();
            ai--;
            bi--;
            addedge(ai, bi, 1, ci);
        }
        ll miniflow;
        ll maxiflow = mcmf(0, N - 1, miniflow);
        int q;
        q = read();
        int u, v;
        while (q--) {
            u = read();
            v = read();
            //printf("maxiflow = %lld\n",maxiflow);
            if (u == 0 || ((1LL * v) / u == maxiflow && (1LL * v) % u > 0) || (1LL * v) / u > maxiflow) {
                puts("NaN");
                continue;
            }
            int idx = v / u;
            ll up = ansarr[idx] * u + (ansarr[idx + 1] - ansarr[idx]) * (v % u);
            //if(v<up) Swap(v, up)
            ll g = gcd(1LL * v, up);
            printf("%lld/%lld\n", up / g, v / g);
        }
    }
    return 0;
}
