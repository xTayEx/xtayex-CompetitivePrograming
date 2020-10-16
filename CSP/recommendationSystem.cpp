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
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define debug(x) cerr << "\033[01;31m" << #x << " = " << x << "\033[0m" \
                      << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct node {
    ll id;
    int val;
    node(ll id, int val)
    {
        this->id = id, this->val = val;
    }
    bool operator<(const node& nn) const
    {
        if (val != nn.val) return val > nn.val;
        return id < nn.id;
    }
    bool operator==(const node& nn) const
    {
        return nn.id == id;
    }
    node() {}
};
set<node> ns;
vector<int> vi;
vector<int> ans[55];
map<ll, node> mp;
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    ll mul = 1e9 + 1;
    for (int i = 1; i <= n; i++) {
        int id, val;
        scanf("%d%d", &id, &val);
        for (int j = 0; j < m; j++) {
            node now = node(j * 1LL * mul + id * 1LL, val);
            ns.insert(now);
            mp[j * 1LL * mul + id * 1LL] = now;
        }
    }
    int q;
    scanf("%d", &q);
    //debug(q);
    while (q--) {
        int opt;
        scanf("%d", &opt);
        if (opt == 1) {
            int type, ID, score;
            scanf("%d%d%d", &type, &ID, &score);
            ns.insert(node(type * mul + (ID * 1LL), score));
            mp[type * mul + (ID * 1LL)] = node(type * mul * 1LL + ID * 1LL, score);
        } else if (opt == 2) {
            int type, ID;
            scanf("%d%d", &type, &ID);
            ns.erase(mp[type * mul + (ID * 1LL)]);
            mp.erase(type * mul + (ID * 1LL));
        } else if (opt == 3) {
            vi.clear();
            int K, tmp;
            scanf("%d", &K);
            for (int i = 0; i < m; i++) {
                scanf("%d", &tmp);
                vi.push_back(tmp);
            }
            for (int i = 0; i <= m; i++) {
                ans[i].clear();
            }
            set<node>::iterator Ite = ns.begin();
            for (; Ite != ns.end(); Ite++) {
                node it = *Ite;
                int pos = it.id / mul;
                if ((int)ans[pos].size() < vi[pos]) {
                    ans[pos].push_back(it.id % mul);
                    K--;
                    if (K <= 0) break;
                }
                if (K <= 0) break;
            }
            for (int i = 0; i < m; i++) {
                if (!ans[i].empty()) {
                    int sz = ans[i].size();
                    //sort(ans[i].begin(), ans[i].end());
                    for (int j = 0; j < sz; j++) {
                        printf("%d%c", ans[i][j], j == sz - 1 ? '\n' : ' ');
                    }
                } else {
                    puts("-1");
                }
            }
        }
    }
    return 0;
}
