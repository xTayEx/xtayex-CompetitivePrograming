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
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 2; i <= n / 2; i++) {
            for (int j = 1; j < i; j++) {
                printf("%d %d\n", j, i);
            }
        }
        for (int i = n / 2 + 1; i <= n; i++) {
            for (int j = 1; j <= n - i; j++) {
                printf("%d %d\n", j, i);
            }
        }
        for (int i = 1; i <= n / 2; i++) {
            for (int j = n - i + 1; j <= n; j++) {
                printf("%d %d\n", i, j);
            }
        }
        for (int i = n / 2 + 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                printf("%d %d\n", i, j);
            }
        }
    }
    return 0;
}
