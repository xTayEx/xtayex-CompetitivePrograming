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
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll a[maxn];
ll sum[maxn];
map<ll, ll> mp;
ll C(ll n)
{
    return (n * (n - 1)) / 2;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        mp.clear();
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%1lld", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + a[i];
        }
        int tmp;
        for (int i = 0; i <= n; i++) {
            tmp = sum[i] - i;
            mp[tmp]++;
        }
        ll ans = 0;
        for (auto it : mp) {
            ans += C(it.second);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
