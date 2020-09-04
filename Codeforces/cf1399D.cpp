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
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[maxn];
queue<int> q1, q0;
vector<int> ans;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ans.clear();
        while (!q1.empty()) q1.pop();
        while (!q0.empty()) q0.pop();
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%1d", &a[i]);
        }
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                if (!q0.empty()) {
                    ans.push_back(ans[q0.front()]);
                    q0.pop();
                } else {
                    ans.push_back(cnt++);
                }
                q1.push(i);
            } else if (a[i] == 0) {
                if (!q1.empty()) {
                    ans.push_back(ans[q1.front()]);
                    q1.pop();
                } else {
                    ans.push_back(cnt++);
                }
                q0.push(i);
            }
        }
        cnt--;
        printf("%d\n", cnt);
        for (auto it : ans) {
            printf("%d ", it);
        }
        puts("");
    }
    return 0;
}
