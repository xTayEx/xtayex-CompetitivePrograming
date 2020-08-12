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
#include <utility>
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define idebug(x) printf("%s = %d\n", #x, x)
#define ddebug(x) printf("%s = %lf\n", #x, x)
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
using namespace std;
using pii = pair<int, int>;
typedef long long ll;
typedef unsigned long long ull;
int dir[][2] = {
    { 0, 1 },
    { 1, 0 },
    { 1, 1 },
    { 1, -1 },
    { -1, 1 },
    { -1, 0 },
    { 0, -1 },
    { -1, -1 }
};
map<pii, bool> vis;
inline void dfs(int x, int y)
{
    idebug(maxn);
    for (int i = 0; i < 8; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        pii now = make_pair(tx, ty);
        if (__gcd(tx, ty) <= 1 || vis[now]) {
            continue;
        }
        vis[now] = 1;
        printf("%d %d\n", tx, ty);
        dfs(tx, ty);
    }
}
int main()
{
    int sx, sy;
    while (scanf("%d%d", &sx, &sy) != EOF) {
        vis.clear();
        dfs(sx, sy);
    }
    return 0;
}
