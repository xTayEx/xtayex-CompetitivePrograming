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
#define debug printf("debug\n")
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using pll = pair<ll, ll>;
map<pll, bool> vis;
ll ans;
ll N, K;
void dfs(ll n, ll k)
{
    if (n > N || k > K)
        return;
    pll now = make_pair(n, k);
    if (vis[now])
        return;
    vis[now] = 1;
    printf("n = %lld, k = %lld\n", n, k);
    ans++;
    dfs(n + k, k);
    dfs(n * k, k);
}
int main()
{
    while (scanf("%lld %lld", &N, &K) != EOF) {
        ans = 0;
        vis.clear();
        for (int i = 1; i <= K; i++) {
            dfs(1, i);
        }
        printf("ans = %lld\n", ans);
    }
    return 0;
}
