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
#define debug(x) cerr << "\033[01;31m" << #x << " = " << x << "\033[0m" \
                      << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct node {
    ll lef, t;
    int flag;
    bool operator<(const node& n) const
    {
        if (lef != n.lef) return lef < n.lef;
        return flag < n.flag;
    }
};
node ns[maxn << 1];
multiset<ll> st;
int main()
{
    int n;
    scanf("%d", &n);
    ll li, ri, ti;
    for (int i = 1; i + 1 <= 2 * n; i += 2) {
        scanf("%lld%lld%lld", &li, &ri, &ti);
        ns[i].lef = li + ti;
        ns[i].t = ti;
        ns[i].flag = 0;

        ns[i + 1].lef = ri;
        ns[i + 1].t = ti;
        ns[i + 1].flag = 1;
    }
    sort(ns + 1, ns + 1 + 2 * n);
    st.clear();
    ll now, ans, cnt;
    now = ans = 0;
    //for (int i = 1; i <= 2 * n; i++) {
        //printf("%lld %lld\n", ns[i].lef, ns[i].t);
    //}
    //puts("-------------------------------");
    for (int i = 1; i <= 2 * n; i++) {
        // 有重叠的时候，取铸剑时间最短的剑
        if (!st.empty()) {
            cnt = (ns[i].lef - now) / (*st.begin());
            ans += cnt, now += cnt * (*st.begin());
        }
        bool type = ns[i].flag;
        if (type) {
            auto it = st.find(ns[i].t);
            st.erase(it);
        } else {
            // 如果没有重叠，则只能铸这一把剑
            if (now <= ns[i].lef - ns[i].t) {
                now = ns[i].lef;
                ans++;
            }
            st.insert(ns[i].t);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
