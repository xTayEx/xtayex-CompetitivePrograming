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
ll A[maxn];
ll ans[maxn];
bool vis[maxn];
vector<int> rings[maxn];
ll n, k;
ll exgcd(ll a, ll b, ll& x, ll& y)
{
    if (a == 0 && b == 0)
        return -1;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
ll inv(ll a, ll n)
{
    ll x, y;
    ll d = exgcd(a, n, x, y);
    if (d == 1)
        return (x % n + n) % n;
    else
        return -1;
}
void solve(int i)
{
    ll sz = rings[i].size();
    ll Inv = inv(k % sz, sz);
    for (int j = 0; j < sz; j++) {
        ans[rings[i][j]] = rings[i][(j + Inv) % sz];
    }
}
int main()
{
    scanf("%lld %lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int now = i;
            while (!vis[now]) {
                rings[cnt].push_back(now);
                vis[now] = 1;
                now = A[now];
            }
            cnt++;
        }
    }
    for (int i = 0; i < cnt; i++) {
        if (rings[i].empty())
            continue;
        solve(i);
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld%c", ans[i], i == n ? '\n' : ' ');
    }
    return 0;
}
