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
vector<int> apos, bpos;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s + 1);
        apos.clear(), bpos.clear();
        int len = strlen(s + 1);
        for (int i = 1; i <= len; i++) {
            if (s[i] == 'A')
                apos.push_back(i);
            else
                bpos.push_back(i);
        }
        int acnt, bcnt;
        acnt = bcnt = 0;
        //int asz = apos.size();
        int bsz = bpos.size();
        int p = 0;
        for (int i = 1; i <= len; i++) {
            if (s[i] == 'A') {
                while (p < bsz && bpos[p] < i) {
                    p++, bcnt++;
                }
                if (p < bsz && bpos[p] > i)
                    p++;
                else
                    acnt++;
            }
        }
        //debug(acnt);
        //debug(bcnt);
        bcnt += (p < bsz ? bsz - p : 0);
        int ans = acnt + bcnt % 2;
        printf("%d\n", ans);
    }
    return 0;
}
