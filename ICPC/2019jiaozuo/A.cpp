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
int a[5];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &a[1], &a[2], &a[3], &a[4]);
        int cnt = 0;
        for (int i = 1; i <= 4; i++) cnt += (a[i] != 0);
        if (cnt == 0)
            puts("Typically Otaku");
        else if (cnt == 1)
            puts("Eye-opener");
        else if (cnt == 2)
            puts("Young Traveller");
        else if (cnt == 3)
            puts("Excellent Traveller");
        else if (cnt == 4)
            puts("Contemporary Xu Xiake");
    }
    return 0;
}
