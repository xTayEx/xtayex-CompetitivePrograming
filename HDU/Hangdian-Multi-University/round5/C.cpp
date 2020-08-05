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
vector<int> pa[maxn * 10];
inline void init(int n)
{
    for (int i = 1; i <= n; i++) {
        pa[i].clear();
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int bnd = 2 * n * (1 << k);
        init(bnd);
        for (int i = 1; i <= bnd; i++) {
            int tmp;
            scanf("%d", &tmp);
            pa[i].push_back(tmp);
        }
        int p = 1;
        int sz;
        for (int i = 0; i < k; i++) {
            int mid = (p + bnd) / 2;
            for (int j = p; j <= mid; j++) {
                sz = pa[j].size();
                for (int k = sz - 1; k >= 0; k--) {
                    pa[mid * 2 - j + 1].push_back(pa[j][k]);
                }
            }
            p = mid + 1;
        }
        for (int i = bnd - 2 * n + 1; i <= bnd; i++) {
            sz = pa[i].size();
            for (int j = sz - 1; j >= 0; j--) {
                printf("%d", pa[i][j]);
                if (i == bnd && j == 0)
                    printf("\n");
                else
                    printf(" ");
            }
        }
    }
    return 0;
}
