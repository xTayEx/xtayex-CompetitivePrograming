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
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll a[maxn], sum[maxn];
map<ll, bool> mp;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    int ans = 0;
    mp[0] = 1;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
        if (mp[sum[i]]) {
            ans++, mp.clear();
            sum[i] = a[i];
            mp[0] = mp[sum[i]] = 1;
        } else {
            mp[sum[i]] = 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
