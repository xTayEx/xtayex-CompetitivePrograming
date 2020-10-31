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
const int maxn = 2e5 + 5;
const int maxm = 1e7 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int arr[maxm + 1];
int cnt[maxm + 1];
int n;
int prime[maxm + 1];
void getprime()
{
    mst(prime, 0);
    for (int i = 2; i <= maxm; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] <= maxm / i; j++) {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
ll f[maxm + 1];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        cnt[arr[i]]++;
    }
    getprime();
    //debug(prime[0]);
    ll ans = 0;
    int Cnt=0;
    for (int i = 1; i < maxm; i++) {
        f[i] = max(f[i], 1LL * cnt[i]);
        for (int j = 1; j <= prime[0] && 1LL * prime[j] * i <= (int)1e7; j++) {
            Cnt++;
            f[i * prime[j]] = max(f[i * prime[j]], f[i] + cnt[i * prime[j]]);
        }
        ans = max(ans, f[i]);
    }
    //debug(Cnt);
    printf("%lld\n", ans);
    return 0;
}
