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
int n, x, y;
vector<ll> ans;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ans.clear();
        scanf("%d%d%d", &n, &x, &y);
        int cnt = 0;
        for (int i = 1; i <= y - x - 1; i++) {
            if ((y - x) % (i + 1) == 0) {
                if (i > n - 2) {
                    break;
                }
                cnt = max(cnt, i);
            }
        }
        int gap = (y - x) / (cnt + 1);
        ans.push_back(x), ans.push_back(y);
        for (int i = 1; i <= cnt; i++) {
            ans.push_back(1LL * (x + i * gap));
        }
        n -= (2 + cnt);
        int now = x - gap;
        while (now > 0 && n > 0) {
            ans.push_back(now);
            n--, now -= gap;
        }
        now = y + gap;
        while (n > 0) {
            ans.push_back(now);
            n--, now += gap;
        }
        int sz = ans.size();
        for (int i = 0; i < sz; i++) {
            printf("%lld%c", ans[i], i == sz - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
