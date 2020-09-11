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
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll fpow(ll a, ll b)
{
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a;
        a = a * a, b >>= 1;
    }
    return ret;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n, s;
        scanf("%lld%lld", &n, &s);
        ll tmpn = n, sum = 0;
        int cnt = 1, pos = 0;
        while (tmpn) {
            sum += tmpn % 10;
            tmpn /= 10;
        }
        if (sum <= s) {
            puts("0");
            continue;
        }
        tmpn = n;
        int sum1 = sum;
        while (tmpn) {
            sum1 -= tmpn % 10;
            if (sum1 + 1 <= s) {
                pos = cnt;
                break;
            }
            tmpn /= 10, cnt++;
        }
        ll pow10 = fpow(10, pos);
        ll tail = n % pow10;
        ll ans = pow10 - tail;
        printf("%lld\n", ans);
    }
    return 0;
}
