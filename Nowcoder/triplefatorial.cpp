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
ll fac[maxn];
inline ll init(ll mod)
{
    fac[0] = 1LL % mod;
    for (ll i = 1; i <= 720; i++) {
        fac[i] = (fac[i - 1] % mod * i % mod) % mod;
    }
    return fac[720];
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n, m;
        scanf("%lld%lld", &n, &m);
        if (n <= 2) {
            if (n == 0) n++;
            printf("%lld\n", n % m);
        } else if (n == 3) {
            if (m <= 720) {
                puts("0");
            } else {
                printf("%lld\n", init(m));
            }
        } else {
            puts("0");
        }
    }
    return 0;
}
