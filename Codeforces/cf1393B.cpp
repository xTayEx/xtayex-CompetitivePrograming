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
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[maxn];
int cnt[maxn];
int num[maxn];
char s[10];
int main()
{
    int n;
    scanf("%d", &n);
    int bnd = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
        bnd = max(bnd, a[i]);
    }
    for (int i = 0; i <= bnd; i++) {
        num[cnt[i]]++;
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int x;
        scanf("%s%d", s, &x);
        if (s[0] == '+') {
            num[cnt[x]]--, cnt[x]++, num[cnt[x]]++, n++;
        } else if (s[0] == '-') {
            num[cnt[x]]--, cnt[x]--, num[cnt[x]]++, n--;
        }
        if (num[1] + 2 * num[2] + 3 * num[3] == n) {
            puts("NO");
        } else {
            int tmp = n - num[1] - 2 * num[2] - 3 * num[3];
            if (tmp >= 8) {
                puts("YES");
            } else if (tmp == 4 || tmp == 5) {
                if (num[2] + num[3] >= 2)
                    puts("YES");
                else
                    puts("NO");
            } else if (tmp == 6 || tmp == 7) {
                if (num[2] != 0 || num[3] != 0)
                    puts("YES");
                else
                    puts("NO");
            }
        }
    }
    return 0;
}
