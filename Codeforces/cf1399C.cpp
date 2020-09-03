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
const int maxn = 50 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int w[maxn];
vector<int> vec[2505];
bool vis[2505][51];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        mst(vis, 0);
        int n;
        scanf("%d", &n);
        for (int i = 0; i < 2505; i++) {
            vec[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &w[i]);
        }
        if (n == 1) {
            puts("0");
            continue;
        }
        int maxisum = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int sum = w[i] + w[j];
                maxisum = max(sum, maxisum);
                if (!vis[sum][i] && !vis[sum][j]) {
                    vec[sum].push_back(i);
                    vec[sum].push_back(j);
                    vis[sum][i] = vis[sum][j] = 1;
                }
            }
        }
        int maxi = 0;
        int ans = -1;
        //int deb = -1;
        for (int i = 0; i <= maxisum; i++) {
            int siz = vec[i].size();
            if (siz % 2 == 0 && siz > maxi) {
                maxi = siz, ans = siz / 2;
                //deb = i;
            }
        }
        //debug(deb);
        printf("%d\n", ans);
    }
    return 0;
}
