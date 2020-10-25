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
#define debug(x) cerr << "\033[01;31m" << #x << " = " << x << "\033[0m" \
                      << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e3 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char mp[maxn][maxn];
int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
char correct[] = { 'S', 'W', 'D', 'A' };
struct node {
    int x, y;
    node(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    bool operator<(const node& nn) const
    {
        if (x != nn.x) return x < nn.x;
        return y < nn.y;
    }
};
queue<node> que;
vector<node> vec;
bool vis[maxn][maxn];
int n, m;
bool check(int row, int col)
{
    return (row <= n && row >= 1 && col <= m && col >= 1);
}
int ans = 0;
void solve(node n)
{
    int row = n.x;
    int col = n.y;
    for (int i = 0; i < 4; i++) {
        int trow = row + dir[i][0];
        int tcol = col + dir[i][1];
        if (check(trow, tcol) && mp[trow][tcol] == correct[i] && !vis[trow][tcol]) {
            ans++;
            //vec.push_back(node(trow, tcol));
            que.push(node(trow, tcol));
            vis[trow][tcol] = 1;
        }
    }
}
int main()
{
    mst(vis, 0);
    ans = 0;
    while (!que.empty()) que.pop();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", mp[i] + 1);
    }
    for (int i = 2; i <= n - 1; i++) {
        if (mp[i][1] == 'A' && !vis[i][1]) {
            ans++, vis[i][1] = 1;
            que.push(node(i, 1));
        }
        if (mp[i][m] == 'D' && !vis[i][m]) {
            ans++, vis[i][m] = 1;
            que.push(node(i, m));
        }
    }
    for (int j = 2; j <= m - 1; j++) {
        if (mp[1][j] == 'W' && !vis[1][j]) {
            ans++, vis[1][j] = 1;
            que.push(node(1, j));
        }
        if (mp[n][j] == 'S' && !vis[n][j]) {
            ans++, vis[n][j] = 1;
            que.push(node(n, j));
        }
    }
    if ((mp[1][1] == 'W' || mp[1][1] == 'A') && !vis[1][1]) {
        ans++, vis[1][1] = 1;
        que.push(node(1, 1));
        vis[1][1] = 1;
    }
    if ((mp[1][m] == 'W' || mp[1][m] == 'D') && !vis[1][m]) {
        ans++, vis[1][m] = 1;
        que.push(node(1, m));
        vis[1][m] = 1;
    }
    if ((mp[n][1] == 'A' || mp[n][1] == 'S') && !vis[n][1]) {
        ans++, vis[n][1] = 1;
        que.push(node(n, 1));
        vis[n][1] = 1;
    }
    if ((mp[n][m] == 'D' || mp[n][m] == 'S') && !vis[n][m]) {
        ans++, vis[n][m] = 1;
        que.push(node(n, m));
        vis[n][m] = 1;
    }
    while (!que.empty()) {
        node now = que.front();
        que.pop();
        solve(now);
    }
    printf("%d\n", ans);
    return 0;
}
