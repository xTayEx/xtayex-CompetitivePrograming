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
#define debug(x) cerr << #x << " = " << x
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll arr[maxn << 1];
ll sum[maxn << 1];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
        arr[i + n] = arr[i];
    }
    for (int i = 1; i < 3; i++) {
        sum[i] = arr[i];
    }
    for (int i = 3; i <= 2 * n; i++) {
        sum[i] = sum[i - 2] + arr[i];
    }
    ll ans = 0;
    for (int i = n + 1; i <= 2 * n; i++) {
        ans = max(ans, sum[i] - sum[i - n - 1]);
    }
    printf("%lld\n", ans);
    return 0;
}
