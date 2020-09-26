#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
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
const int maxn = 1e3 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[maxn];
bool vis[maxn];
vector<int> ans;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ans.clear();
        mst(vis, 0);
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + 1 + n);
        ans.push_back(a[n]);
        vis[n] = 1;
        int maxigcd = a[n];
        for (int i = 1; i < n; i++) {
            int tmpans = -1, pos = -1;
            for (int j = 1; j <= n; j++) {
                if (vis[j]) continue;
                int tmp = gcd(a[j], maxigcd);
                if (tmp > tmpans) {
                    tmpans = tmp, pos = j;
                }
            }
            vis[pos] = 1, ans.push_back(a[pos]);
            maxigcd = tmpans;
        }
        for (auto it : ans) {
            printf("%d ", it);
        }
        puts("");
    }
    return 0;
}
