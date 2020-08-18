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
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, cnt = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) cnt++;
            else break;
        }
        if (cnt == n) {
            if (n % 2 == 1) puts("First");
            else puts("Second");
        } else {
            if (cnt % 2 == 1) puts("Second");
            else puts("First");
        }
    }
    return 0;
}
