
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 1e3 + 7;
int n, m;
struct Node {
    int x, y;
    int operator<(const Node& b) const
    {
        return x < b.x;
    }
} node[maxn];
int a[maxn], vis[maxn], num;
int dfs(int i)
{
    if (i >= m || i > 0 && node[i - 1].x != node[i].x && vis[node[i - 1].x] != a[node[i - 1].x]) {
        if (num == 0)
            return 1;
        else
            return 0;
    }
    int tmp = num;
    vis[node[i].x] += 1;
    vis[node[i].y] += 1;
    if (vis[node[i].x] <= a[node[i].x] && vis[node[i].y] <= a[node[i].y]) {
        if (vis[node[i].x] == a[node[i].x]) {
            num--;
        }
        if (vis[node[i].y] == a[node[i].y]) {
            num--;
        }
        if (dfs(i + 1))
            return 1;
        num = tmp;
    }
    vis[node[i].x] -= 1;
    vis[node[i].y] -= 1;
    if (dfs(i + 1))
        return 1;
    return 0;
}
int main()
{
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);
    while (cin >> n) {
        memset(vis, 0, sizeof(vis));
        cin >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            int c, b;
            cin >> c >> b;
            if (c > b)
                swap(c, b);
            node[i].x = c;
            node[i].y = b;
        }
        sort(node, node + m);
        num = n;
        if (dfs(0)) {
            cout << "Yes\n";
        } else
            cout << "No\n";
    }
    return 0;
}
