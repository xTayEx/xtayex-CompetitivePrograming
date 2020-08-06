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
const int N = 5e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll add[N], minu[N], sum[N];
int main()
{
    for (ll len = 3; len <= maxn; len++) {
        for (int base = 1; base * len <= maxn; base++) {
            int pos = base * len + 3;
            add[pos]++;
            add[(base + 2) * len - 3 + 2]--;
            minu[(base + 1) * len + 1]++;
            minu[(base + 2) * len - 3 + 2]--;
        }
    }
    for (int i = 3; i <= maxn; i++) {
        add[i] += add[i - 2];
        minu[i] += minu[i - 1];
    }
    for (int i = 3; i <= maxn; i++) {
        add[i] -= minu[i];
    }
    for (int i = 3; i <= maxn; i++) {
        add[i] += add[i - 1];
        sum[i] = sum[i - 1] + add[i];
    }
    int T;
    scanf("%d", &T);
    int kase = 0;
    while (T--) {
        int L, R;
        scanf("%d %d", &L, &R);
        printf("Case #%d: %lld\n", ++kase, sum[R] - sum[L - 1]);
    }
    return 0;
}
