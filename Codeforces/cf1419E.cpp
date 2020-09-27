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
set<int> st;
vector<int> ans;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        st.clear();
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i != 1) st.insert(i);
                if (n / i != 1) st.insert(n / i);
            }
        }
        ans.clear();
        ans.push_back(*st.begin());
        st.erase(st.begin());
        set<int>::iterator it;
        int sz = st.size();
        for (int i = 0; i < sz; i++) {
            bool flag = 0;
            int tmp;
            for (it = st.begin(); it != st.end(); it++) {
                int bac = ans.back();
                if (gcd(*it, bac) > 1) {
                    flag = 1, tmp = *it;
                    //debug(tmp);
                    break;
                }
            }
            if (flag) {
                ans.push_back(tmp);
                st.erase(it);
            } else {
                ans.push_back(*st.begin());
                st.erase(st.begin());
            }
        }
        int cnt = 0;
        for (int i = 0; i + 1 < (int)ans.size(); i++) {
            if (gcd(ans[i], ans[i + 1]) == 1) {
                cnt++;
            }
        }
        cnt += (gcd(ans.back(), ans[0]) == 1 ? 1 : 0);
        for (auto it : ans) {
            printf("%d ", it);
        }
        puts("");
        printf("%d\n", cnt);
    }
    return 0;
}
