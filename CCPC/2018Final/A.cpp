#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <cmath>
#include <unordered_map>
#define mst(a,b) memset((a),(b),sizeof(a))
#define debug(x) cerr << "\033[01;31m" << #x << " = " << x << "\033[0m" << "\n"
#define INF 0x3f3f3f3f
#define lson lef,mid,rt<<1
#define rson mid+1,rig,rt<<1|1
const int maxn=1e5+5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct node {
    int d, t;
    bool operator<(const node& nn) const
    {
        return d < nn.d;
    }
} ns[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    int kase = 0;
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i].d);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i].t);
        }
        sort(ns, ns + n);
        int cnt = -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + ns[i].t <= m) {
                sum += ns[i].t;
            } else {
                cnt = i;
                break;
            }
        }
        if (cnt == -1) cnt = n;
        printf("Case %d: %d\n", ++kase, cnt);
    }
    return 0;
}
