
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
#define idebug(x) printf("%s = %d\n", #x, x)
#define ddebug(x) printf("%s = %lf\n", #x, x)
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e6 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using pii = pair<int, int>;
vector<pii> vec;
unordered_map<int, int> cnt;
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        int a;
        for (int j = 1; j <= k; j++) {
            scanf("%d", &a);
            vec.push_back({ a, i });
        }
    }
    sort(vec.begin(), vec.end());
    cnt.clear();
    int sz = vec.size();
    int lef = 0;
    int tot = 0, ans = INF;
    for (int i = 0; i < sz; i++) {
        if (cnt[vec[i].second] == 0) {
            cnt[vec[i].second]++, tot++;
        } else {
            cnt[vec[i].second]++;
        }
        while (tot > m) {
            if (cnt[vec[i].second] > 1) {
                lef++, cnt[vec[i].second]--;
            } else {
                cnt[vec[i].second] = 0;
                lef++, tot--;
            }
        }
        if (tot == m)
            ans = min(ans, vec[i].first - vec[lef].first);
    }
    printf("%d\n", ans);
    return 0;
}
