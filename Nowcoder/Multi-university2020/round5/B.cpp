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
    int v;
    int w;
};
vector<node> Graph[maxn];
int dis[maxn];
inline void dfs(int now, int fa)
{
    int sz = Graph[now].size();
    int v;
    for (int i = 0; i < sz; i++) {
        v = Graph[now][i].v;
        if (v == fa)
            continue;
        dis[v] = dis[now] ^ Graph[now][i].w;
        dfs(v, now);
    }
}
int trie[maxn * 30][2];
int tot = 0;
ll ans = 0;
inline void insert(int x)
{
    int now = 0;
    for (int i = 29; i >= 0; i--) {
        int bit = (x >> i) & 1;
        if (trie[now][bit] == 0) {
            trie[now][bit] = ++tot;
        }
        now = trie[now][bit];
    }
}
int search(int x)
{
    int now = 0;
    int ret = 0;
    for (int i = 29; i >= 0; i--) {
        int bit = (x >> i) & 1;
        if (trie[now][bit] == 0) {
            now = trie[now][bit ^ 1];
            ret += (1 << i);
        } else {
            now = trie[now][bit];
        }
    }
    return ret;
}
void solve(int lef, int rig, int dep)
{
    if (dep == -1)
        return;
    if (lef > rig)
        return;
    int lefval = (dis[lef] >> dep) & 1;
    int rigval = (dis[rig] >> dep) & 1;
    if (lefval == rigval) {
        solve(lef, rig, dep - 1);
        return;
    }
    int mid = lef;
    for (int i = lef; i <= rig; i++) {
        int tmp = (dis[i] >> dep) & 1;
        if (tmp != 0) {
            mid = i - 1;
            break;
        }
    }
    solve(lef, mid, dep - 1);
    solve(mid + 1, rig, dep - 1);
    for (int i = lef; i <= mid; i++) {
        insert(dis[i]);
    }
    int mini = INF;
    for (int i = mid + 1; i <= rig; i++) {
        int tmp = search(dis[i]);
        //printf("tmp = %d\n",tmp);
        mini = min(mini, tmp);
    }
    ans += mini;
    for (int i = 0; i <= tot; i++) {
        trie[i][0] = trie[i][1] = 0;
    }
    tot = 0;
}
int main()
{
    ans = 0;
    tot = 0;
    int N;
    scanf("%d", &N);
    int U, V, W;
    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d %d", &U, &V, &W);
        U++, V++;
        Graph[U].push_back({ V, W });
        Graph[V].push_back({ U, W });
    }
    dfs(1, -1);
    sort(dis + 1, dis + 1 + N);
    solve(1, N, 29);
    printf("%lld\n", ans);
    return 0;
}
