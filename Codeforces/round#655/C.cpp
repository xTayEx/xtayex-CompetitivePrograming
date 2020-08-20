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
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int arr[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        fill(arr + 1, arr + 1 + n, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }
        int cnt = 0;
        int lef = 1, rig = 1;
        while (lef <= n && rig <= n) {
            rig = lef;
            while (rig <= n && arr[rig] != rig)
                rig++;
            if (rig - lef >= 1) cnt++;
            lef = rig;
            while (lef <= n && arr[lef] == lef)
                lef++;
        }
        if (cnt == 0) puts("0");
        else if (cnt == 1) puts("1");
        else puts("2");
    }
    return 0;
}
