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
int n;
bool check(int mid)
{
    int lef_2cnt, lef_0cnt;
    int rig_2cnt, rig_0cnt;
    lef_2cnt = mid;
    lef_0cnt = rig_2cnt = rig_0cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '2') {
            if (lef_2cnt != 0)
                lef_2cnt--, lef_0cnt++;
            else if (rig_2cnt != 0)
                rig_2cnt--, rig_0cnt++;
        } else if (s[i] == '0') {
            if (lef_0cnt != 0)
                lef_0cnt--, rig_2cnt++;
            else if (rig_0cnt != 0)
                rig_0cnt--;
        }
    }
    return (lef_2cnt == 0 && lef_0cnt == 0 && rig_2cnt == 0 && rig_0cnt == 0);
}
int main()
{
    while (scanf("%d%s", &n, s + 1) != EOF) {
        int lef = 1, rig = n / 4;
        int mid = (lef + rig) / 2;
        while (lef < rig) {
            mid = (lef + rig) / 2;
            if (check(mid)) {
                lef = mid + 1;
            } else {
                rig = mid;
            }
        }
        if (!check(lef)) lef--;
        int ans = lef;
        printf("%d\n", ans);
    }
    return 0;
}
