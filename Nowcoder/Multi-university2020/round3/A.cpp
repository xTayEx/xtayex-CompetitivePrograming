
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
#define debug printf("debug\n")
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 2e6 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char s[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        int ba = 0;
        int ans = 0;
        for (int i = n; i >= 1; i--) {
            if (s[i] == '0') {
                ba++;
            } else if (s[i] == '1') {
                if (ba > 0) {
                    ba--;
                    ans++;
                } else
                    ba++;
            } else if (s[i] == '2') {
                ans++;
            } else if (s[i] == '3') {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
