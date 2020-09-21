#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
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
int a[maxn], l[maxn];
vector<int> unl, ans;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        ans.clear(), unl.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &l[i]);
            if (l[i] == 0) unl.push_back(a[i]);
        }
        sort(unl.begin(), unl.end(), greater<int>());
        int idx = 0;
        for (int i = 1; i <= n; i++) {
            if (l[i] == 1)
                ans.push_back(a[i]);
            else
                ans.push_back(unl[idx++]);
        }
        for (auto& it : ans) {
            printf("%d ", it);
        }
        puts("");
    }
    return 0;
}
