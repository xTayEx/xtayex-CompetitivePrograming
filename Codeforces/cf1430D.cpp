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
char s[maxn];
struct node {
    int st, ed;
    int len;
    node(int st, int ed)
    {
        this->st = st;
        this->ed = ed;
        this->len = ed - st + 1;
    }
};
vector<node> ns;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        ns.clear();
        int p, st;
        p = st = 1;
        while (p <= n && st <= n) {
            while (st <= n && s[st] == s[p]) p++;
            ns.emplace_back(st, p - 1);
            st = p;
        }
        int ans;
        ans = 0;
        int siz = ns.size();
        p = 0;
        bool flag = 0;
        debug(siz);
        for (int i = 0; i < siz; i++) {
            while (p < siz && ns[p].len == 1) p++;
            if (p < siz) ns[p].len--;
            if (p >= siz) {
                flag = 1;
                //debug(i);
                ans = i + ceil(((siz - i) * 1.0) / 2.0);
                break;
            }
            if (p <= i) p = i + 1;
        }
        if (flag)
            printf("%d\n", ans);
        else
            printf("%d\n", siz);
    }
    return 0;
}
