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
const int maxn = 2e2 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll calc(ll val)
{
    return (val * (val - 1)) / 2;
}
int main()
{
    int T;
    scanf("%d", &T);
    int kase = 0;
    while (T--) {
        ll r, b;
        scanf("%lld%lld", &r, &b);
        ll up = calc(r);
        ll down = calc(r + b);
        ll g = __gcd(up, down);
        printf("Case #%d: %lld/%lld\n", ++kase, calc(r) / g, calc(r + b) / g);
    }
    return 0;
}
