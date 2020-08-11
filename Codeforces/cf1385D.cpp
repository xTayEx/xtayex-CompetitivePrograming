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
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char s[maxn];
int sum[maxn][26];
int solve(int nowlen, int ch, int lef, int rig)
{
    if (lef > rig)
        return 0;
    if (lef == rig) {
        return s[lef] - 'a' + 1 == ch ? 0 : 1;
    }
    int mid = (lef + rig) / 2;
    int lefcnt = (nowlen >> 1) - (sum[mid][ch] - sum[lef - 1][ch]);
    int rigcnt = (nowlen >> 1) - (sum[rig][ch] - sum[mid][ch]);
    int ans1 = lefcnt + solve(nowlen >> 1, ch + 1, mid + 1, rig);
    int ans2 = rigcnt + solve(nowlen >> 1, ch + 1, lef, mid);
    return min(ans1, ans2);
}
inline void init()
{
    for (int i = 0; i <= 26; i++) {
        sum[0][i] = 0;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        init();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 26; j++) {
                sum[i][j] = sum[i - 1][j];
            }
            sum[i][s[i] - 'a' + 1]++;
        }
        int Ans = solve(n, 1, 1, n);
        printf("%d\n", Ans);
    }
    return 0;
}
