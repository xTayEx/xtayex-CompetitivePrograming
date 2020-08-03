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
    int a, b;
};
node ns[maxn];
int maxi;
unordered_map<int, bool> vis;
vector<int> ans;
void show()
{
    int sz = ans.size();
    for (int i = 0; i < sz; i++) {
        printf("%d ", ans[i]);
    }
    puts("");
}
void dfs(int cur, int n, int now)
{
    maxi = max(maxi, now);
    if (cur > n) {
        show();
        ans.clear();
        return;
    }
    //printf("cur = %d\n",cur);
    if (!vis[ns[cur].a]) {
        vis[ns[cur].a] = 1;
        ans.push_back(ns[cur].a);
        dfs(cur + 1, n, now + 1);
        ans.pop_back();
        vis[ns[cur].a] = 0;
    }
    if (!vis[ns[cur].b]) {
        vis[ns[cur].b] = 1;
        ans.push_back(ns[cur].b);
        dfs(cur + 1, n, now + 1);
        ans.pop_back();
        vis[ns[cur].b] = 0;
    }
    if (vis[ns[cur].a] && vis[ns[cur].b])
        dfs(cur + 1, n, now);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        vis.clear(), ans.clear();
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &ns[i].a, &ns[i].b);
        }
        maxi = 0;
        dfs(1, n, 0);
        printf("%d\n", maxi);
        puts("------------------------------------------");
    }
    return 0;
}
