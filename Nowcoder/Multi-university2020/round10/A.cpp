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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
unordered_map<int, bool> mp;
vector<int> ans;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ans.clear(), mp.clear();
        int p;
        scanf("%d", &p);
        bool flag = 1;
        for (int i = 0; i < p - 1; i++) {
            if (i == 0)
                ans.push_back(1), mp[1] = 1;
            else {
                int tmp1 = (ans[i - 1] * 2) % p;
                int tmp2 = (ans[i - 1] * 3) % p;
                if (mp.count(tmp1) == 0 && tmp1 > 0) {
                    ans.push_back(tmp1);
                    mp[tmp1] = 1;
                } else if (mp.count(tmp2) == 0 && tmp2 > 0) {
                    ans.push_back(tmp2);
                    mp[tmp2] = 1;
                } else {
                    flag = 0;
                    break;
                }
            }
        }
        if (!flag) {
            puts("-1");
            continue;
        }
        int sz = ans.size();
        for (int i = 0; i < sz; i++) {
            printf("%d%c", ans[i], i == sz - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
