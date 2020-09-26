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
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e3 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, x;
        scanf("%d%d", &n, &x);
        int sum = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] - x == 0) cnt++;
            sum += a[i] - x;
        }
        if (cnt == n) {
            puts("0");
        } else if (sum == 0 || cnt > 0) {
            puts("1");
        } else {
            puts("2");
        }
    }
    return 0;
}
