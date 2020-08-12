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
#define idebug(x) printf("%s = %d\n", #x, x)
#define ddebug(x) printf("%s = %lf\n", #x, x)
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
using namespace std;
using pii = pair<int, int>;
typedef long long ll;
typedef unsigned long long ull;
struct point {
    int x, y;
} ps[2005];
struct line {
    int i, j;
    ll dis;
    bool operator<(const line& l) const
    {
        return dis > l.dis;
    }
};
ll sqr(ll x)
{
    return x * x;
}
ll calc_dis(int i, int j)
{
    ll ret = (sqr(ps[i].x - ps[j].x) + sqr(ps[i].y - ps[j].y));
    return ret;
}
vector<line> ls;
unordered_map<int, bool> mp;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ls.clear(), mp.clear();
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &ps[i].x, &ps[i].y);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ll d = calc_dis(i, j);
                ls.push_back({ i, j, d });
            }
        }
        sort(ls.begin(), ls.end());
        int sz = ls.size();
        int cnt = n;
        //idebug(cnt);
        for (int i = 0; i < sz; i++) {
            //pii now = make_pair(ls[i].i, ls[i].j);
            if (mp[ls[i].i] == 0 && mp[ls[i].j] == 0) {
                cnt -= 2, mp[ls[i].i] = 1, mp[ls[i].j] = 1;
            }
        }
        //idebug(cnt);
        if (cnt == 0) {
            puts("YES");
        } else {
            if (cnt == 1 && mp[1]) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
    return 0;
}
