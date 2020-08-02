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
int arr[maxn];
int sum[maxn];
unordered_map<int, bool> mp;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }
        int ans = 0;
        sum[0] = 0, mp.clear(), mp[0] = 1;
        for (int i = 1; i <= n; i++) {
            sum[i] = (sum[i - 1] + arr[i]) % k;
            if (mp[sum[i]] == 1) {
                ans++, mp.clear(), mp[0] = 1;
                sum[i] = 0;
            } else {
                mp[sum[i]] = 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
