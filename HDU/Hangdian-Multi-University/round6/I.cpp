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
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ll b, x;
        scanf("%lld %lld", &b, &x);
        if (b < x) {
            puts("F");
        } else {
            if (b % x == 1LL)
                puts("T");
            else
                puts("F");
        }
    }
    return 0;
}
