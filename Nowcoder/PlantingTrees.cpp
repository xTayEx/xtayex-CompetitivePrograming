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
int mat[505][505];
int mxque[maxn];
int mnque[maxn];
int mini[505];
int maxi[505];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &mat[i][j]);
            }
        }
        int ans = 0;
        for (int lef = 1; lef <= n; lef++) {
            for (int j = 1; j <= n; j++) {
                mini[j] = INF;
                maxi[j] = 0;
            }
            for (int rig = lef; rig <= n; rig++) {
                int lefbnd = 1;
                for (int j = 1; j <= n; j++) {
                    maxi[j] = max(maxi[j], mat[rig][j]);
                    mini[j] = min(mini[j], mat[rig][j]);
                }
                int mxql = 1;
                int mxqr = 0;
                int mnql = 1;
                int mnqr = 0;
                for (int j = 1; j <= n; j++) {
                    while (mxql <= mxqr && maxi[mxque[mxqr]] < maxi[j])
                        mxqr--;
                    mxque[++mxqr] = j;
                    while (mnql <= mnqr && mini[mnque[mnqr]] > mini[j])
                        mnqr--;
                    mnque[++mnqr] = j;
                    while (mxql <= mxqr && mnql <= mnqr && lefbnd <= j && maxi[mxque[mxql]] - mini[mnque[mnql]] > m) {
                        lefbnd++;
                        while (mxql <= mxqr && mxque[mxql] < lefbnd)
                            mxql++;
                        while (mnql <= mnqr && mnque[mnql] < lefbnd)
                            mnql++;
                    }
                    if (maxi[mxque[mxql]] - mini[mnque[mnql]] <= m) {
                        ans = max(ans, (rig - lef + 1) * (j - lefbnd + 1));
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
