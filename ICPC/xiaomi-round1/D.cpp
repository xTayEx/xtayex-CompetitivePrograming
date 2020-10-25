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
#define debug(x) cerr << "\033[01;31m" << #x << " = " << x << "\033[0m" \
                      << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 3e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct Edge {
    int to, nxt;
    bool cut;
} edge[maxn];
int head[maxn];
int tot;
int Low[maxn], DFN[maxn], stk[maxn];
int Index, Top;
bool Instack[maxn];
bool cut[maxn];
int addblock[maxn];
int bridge;
void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].nxt = head[u];
    edge[tot].cut = false;
    head[u] = tot++;
}
void tarjan(int u, int pre)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    stk[Top++] = u;
    Instack[u] = true;
    int son = 0;
    int pre_cnt = 0;
    for (int i = head[u]; i != -1; i = edge[i].nxt) {
        v = edge[i].to;
        if (v == pre && pre_cnt == 0) {
            pre_cnt++;
            continue;
        }
        if (!DFN[v]) {
            son++;
            tarjan(v, u);
            if (Low[u] > Low[v]) Low[u] = Low[v];
            if (Low[v] > DFN[u]) {
                bridge++;
                edge[i].cut = true;
                edge[i ^ 1].cut = true;
            }
            if (u != pre && Low[v] >= DFN[u]) {
                cut[u] = true;
                addblock[u]++;
            }
        } else if (Low[u] > DFN[v]) {
            Low[u] = DFN[v];
        }
    }
    if (u == pre && son > 1) cut[u] = true;
    if (u == pre) addblock[u] = son - 1;
    Instack[u] = false;
    Top--;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
    }
}
