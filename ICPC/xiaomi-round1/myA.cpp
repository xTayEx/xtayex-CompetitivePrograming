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
#define debug(x) cerr << "\033[01;31m" << #x << " = " << x << "\033[0m" \
                      << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n;
int arr[maxn];
unordered_map<int, int> cnt;
int ans;
void dfs(int idx, int tot)
{
    ans = max(ans, tot);
    if (idx >= n) return;
    for (int i = 2; i <= arr[n - 1] / arr[idx]; i++) {
        int pos = lower_bound(arr, arr + n, arr[idx] * i) - arr;
        if (pos == n || arr[idx] * i != arr[pos]) continue;
        dfs(pos, tot + cnt[arr[pos]]);
    }
}
int main()
{
    ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        cnt[arr[i]]++;
    }
    arr[n] = 1;
    sort(arr, arr + n + 1);
    n = unique(arr, arr + n + 1) - arr;
    dfs(0, 0);
    ans += cnt[1];
    printf("%d\n", ans);
}
