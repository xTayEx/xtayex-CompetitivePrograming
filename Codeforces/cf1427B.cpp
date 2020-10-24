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
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char s[maxn];
struct node {
    int st, ed, len;
    node(int st, int ed)
    {
        this->st = st;
        this->ed = ed;
        len = ed - st;
    }
    bool operator<(const node& nn) const
    {
        return len < nn.len;
    }
};
vector<node> wins, loses;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", s + 1);
        int p, q;
        p = 1, q = 2;
        wins.clear(), loses.clear();
        int wincnt = 0, losecnt = 0;
        for (int i = 1; i <= n; i++) {
            wincnt += (s[i] == 'W');
            losecnt += (s[i] == 'L');
        }
        if (losecnt <= k) {
            printf("%d\n", 2 * n - 1);
            continue;
        }
        if (losecnt == n) {
            printf("%d\n", max(2 * k - 1, 0));
            continue;
        }
        if (wincnt == n) {
            printf("%d\n", 2 * n - 1);
            continue;
        }
        while (p <= n && q <= n + 1) {
            while (q <= n + 1 && s[p] == s[q] && s[p] == 'W') q++;
            if (s[p] == 'W') {
                wins.emplace_back(p, q);
            }
            p = q, q = p + 1;
        }
        p = 1, q = 2;
        while (p <= n && q <= n + 1) {
            while (q <= n + 1 && s[p] == s[q] && s[p] == 'L') q++;
            if (s[p] == 'L') {
                loses.emplace_back(p, q);
            }
            p = q, q = p + 1;
        }
        int winsz = wins.size();
        int losessz = loses.size();
        sort(loses.begin(), loses.end());
        int gap = 0, tmpk = k;
        for (int i = 0; i < losessz; i++) {
            if(loses[i].st == 1 || loses[i].ed - 1 == n)
                continue;
            if (loses[i].len <= tmpk) {
                tmpk -= loses[i].len, gap++;
            }
        }
        int ans = 2 * (wincnt + k) - winsz + gap;
        printf("%d\n", ans);
    }
    return 0;
}
