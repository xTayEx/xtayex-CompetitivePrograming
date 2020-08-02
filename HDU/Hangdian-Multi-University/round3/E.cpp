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
const int mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int wei[maxn];
int pre[maxn];
inline void init(int n)
{
    for (int i = 0; i <= n; i++) {
        pre[i] = i;
    }
}
int findr(int x)
{
    if (x == pre[x])
        return x;
    return pre[x] = findr(pre[x]);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &wei[i]);
        }
        int u, v;
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &u, &v);
            int fu=findr(u);
            int fv=findr(v);
            if(fu!=fv){

            }
        }
    }
}
