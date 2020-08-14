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
const long long mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char s[maxn], t[maxn];
int nxt[maxn];
void getnxt(char* p)
{
    nxt[0] = -1;
    int k = -1, j = 0;
    while (p[j]) {
        if (k == -1 || p[k] == p[j]) {
            j++, k++;
            nxt[j] = (p[k] != p[j] ? k : nxt[k]);
        } else {
            k = nxt[k];
        }
    }
}
unordered_map<int, bool> mp;
void kmp(char* s, char* p)
{
    getnxt(p);
    int i = 0, j = 0;
    while (s[i]) {
        if (j == -1 || s[i] == p[j]) {
            i++, j++;
        } else {
            j = nxt[j];
        }
        if (j >= 0 && !p[j]) {
            mp[i] = 1, j = nxt[j];
        }
    }
}
int dp[maxn], sum1[maxn], sum2[maxn];
int main()
{
    mp.clear();
    scanf("%s%s", s + 1, t + 1);
    int m = strlen(t + 1);
    int n = strlen(s + 1);
    kmp(s + 1, t + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (!mp[i]) {
            dp[i] = dp[i - 1] % mod;
        } else {
            dp[i] = ((i - m + 1) % mod + sum2[i - m] % mod) % mod;
        }
        sum1[i] = (sum1[i - 1] + dp[i]) % mod;
        sum2[i] = (sum2[i - 1] + sum1[i]) % mod;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i]) % mod;
    }
    printf("%d\n", ans);
    return 0;
}
