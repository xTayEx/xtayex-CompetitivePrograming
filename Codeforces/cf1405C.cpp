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
const int maxn = 3e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char s[maxn];
int n, k;
bool check()
{
    int st = n - k;
    int cnt0 = 0, cnt1 = 0, cntmark = 0;
    for (int i = st; i < n; i++) {
        if (s[i] == '0')
            cnt0++;
        else if (s[i] == '1')
            cnt1++;
        else if (s[i] == '?')
            cntmark++;
    }
    int sub = abs(cnt0 - cnt1);
    //debug((cntmark < sub));
    //debug((cntmark & 1));
    //debug(cntmark);
    if (cntmark < sub) return 0;
    cntmark -= sub;
    if (cntmark & 1) return 0;
    return 1;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        scanf("%s", s);
        bool flag = 1;
        for (int i = 0; i + k < n; i++) {
            if (s[i] == s[i + k]) {
                flag = 1;
            } else if (s[i] != '?' && s[i + k] == '?') {
                flag = 1, s[i + k] = s[i];
            } else if (s[i] != '?' && s[i + k] != '?' && s[i] != s[i + k]) {
                flag = 0;
                break;
            }
        }
        if (flag && check())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
