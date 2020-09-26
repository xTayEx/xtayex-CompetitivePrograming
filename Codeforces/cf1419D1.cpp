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
int a[maxn];
vector<int> ans;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    if (n < 3) {
        puts("0");
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        return 0;
    }
    sort(a + 1, a + 1 + n);
    int st = upper_bound(a + n / 2 + 1, a + 1 + n, a[1]) - a;
    if (st > n) {
        puts("0");
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        return 0;
    }
    ans.push_back(a[st]);
    ans.push_back(a[1]);
    ans.push_back(a[st + 1]);
    int p = 2, cnt = 0;
    int tot = 3;
    for (int i = st + 2; i <= n; i++) {
        ans.push_back(a[p]);
        ans.push_back(a[i]);
        p++, tot += 2;
    }
    while (tot < n) {
        ans.push_back(a[p]), tot++;
    }
    for (int i = 1; i + 1 < n; i++) {
        debug(ans[i]), debug(ans[i - 1]), debug(ans[i + 1]);
        if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    for (auto it : ans) {
        printf("%d ", it);
    }
    return 0;
}
