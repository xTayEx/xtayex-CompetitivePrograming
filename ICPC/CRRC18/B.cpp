#include <iostream>
#include <queue>
using namespace std;
int a[1007][1007], b[1007][1007];
int n, m, k;
struct node {
    int x, y, w;
    node(int a = 0, int b = 0, int c = 0)
    {
        x = a;
        y = b;
        w = c;
    }
};
int mo[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
int bfs()
{
    queue<node> q;
    int ans = k;
    for (int i = 0; i < n; i++) {
        if (b[0][i] == -1) {
            ans = min(max(0, a[0][i]), ans);
        } else if (a[0][i]) {
            q.push(node(0, i, a[0][i]));
            b[0][i] = a[0][i];
        }
        if (b[n - 1][i] == -1) {
            ans = min(max(0, a[n - 1][i]), ans);
        } else if (a[n - 1][i]) {
            q.push(node(n - 1, i, a[n - 1][i]));
            b[n - 1][i] = a[n - 1][i];
        }
    }
    for (int i = 1; i < n - 1; i++) {
        if (b[i][0] == -1) {
            ans = min(max(0, a[i][0]), ans);
        } else if (a[i][0]) {
            q.push(node(i, 0, a[i][0]));
            b[i][0] = a[i][0];
        }
        if (b[i][n - 1] == -1) {
            ans = min(max(0, a[i][n - 1]), ans);
        } else if (a[i][n - 1]) {
            q.push(node(i, n - 1, a[i][n - 1]));
            b[i][n - i] = a[i][n - i];
        }
    }
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, w = q.front().w;
        q.pop();
        if (b[x][y] != w) continue;
        for (int i = 0; i < 4; i++) {
            int tx = x + mo[i][0], ty = y + mo[i][1];
            if (tx >= 0 && tx < n && ty >= 0 && ty < n && a[tx][ty] != 0) {
                int nw = max(a[tx][ty], w);
                if (b[tx][ty] == -1) {
                    ans = min(ans, nw);
                } else if (b[tx][ty] == 0 || b[tx][ty] > nw) {
                    b[tx][ty] = nw;
                    q.push(node(tx, ty, nw));
                }
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        b[x][y] = -1;
        a[x][y] = -1;
    }
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = i;
    }
    cout << bfs() << endl;
}
