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
using pii = pair<int, int>;
vector<pii> vec;
vector<pii> ansvec;
unordered_map<int, int> st, ed;
int solve(int n)
{
    st.clear(), ed.clear();
    int sz = vec.size();
    for (int i = 0; i < sz; i++) {
        if (!st[vec[i].first]) {
            st[vec[i].first] = i + 1;
        }
        if (!st[vec[i].second]) {
            st[vec[i].second] = i + 1;
        }
        ed[vec[i].first] = i + 1;
        ed[vec[i].second] = i + 1;
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        ret += (ed[i] - st[i] + 1);
    }
    return ret;
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        vec.clear();
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                vec.push_back({ i, j });
            }
        }
        for (auto& it : vec) {
            printf("%d %d\n", it.first, it.second);
        }
        puts("++++++++++++++++++++++++");
        int ans = 0;
        do {
            int res = solve(n);
            if (res > ans) {
                ans = res;
                //copy(vec.begin(),vec.end(),ansvec.begin());
            }
        } while (next_permutation(vec.begin(), vec.end()));
        printf("%d\n", ans);
        for (auto& it : ansvec) {
            printf("%d %d\n", it.first, it.second);
        }
        puts("--------------------------------");
    }
    return 0;
}
