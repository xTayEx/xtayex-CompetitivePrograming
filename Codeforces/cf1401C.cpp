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
ll a[maxn], b[maxn];
vector<int> vi;
int main()
{
    //freopen("./cf1401C.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        //debug(T);
        vi.clear();
        int n;
        scanf("%d", &n);
        ll mini = 0x3f3f3f3f3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            b[i] = a[i], mini = min(a[i], mini);
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) {
                vi.push_back(b[i]);
            }
        }
        int sz = vi.size();
        if (sz == 1) {
            puts("NO");
        } else if (sz == 0) {
            puts("YES");
        } else {
            bool flag = 1;
            for (int i = 0; i < sz; i++) {
                if (vi[i] % mini != 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}
