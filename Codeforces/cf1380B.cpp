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
char ch[] = { 'P', 'R', 'S' };
int cnt[3];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        mst(cnt, 0);
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        for (int i = 1; i <= len; i++) {
            if (s[i] == 'R')
                cnt[0]++;
            else if (s[i] == 'S')
                cnt[1]++;
            else if (s[i] == 'P')
                cnt[2]++;
        }
        int maxi = -1;
        int idx = 0;
        for (int i = 0; i < 3; i++) {
            if (cnt[i] > maxi) {
                maxi = cnt[i], idx = i;
            }
        }
        char ans = ch[idx];
        for (int i = 1; i <= len; i++) {
            printf("%c", ans);
        }
        puts("");
    }
    return 0;
}
