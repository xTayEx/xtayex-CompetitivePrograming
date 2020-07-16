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
int n, m, k;
int A[5005][5005];
inline int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
inline int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
struct node {
    int val;
    int id;
};
void getrow_maxi(int row)
{
    deque<node> que;
    for (int j = 1; j < k; j++) {
        while (!que.empty() && que.back().val < A[row][j]) {
            que.pop_back();
        }
        que.push_back({ A[row][j], j });
    }
    for (int j = k; j <= m; j++) {
        while (!que.empty() && que.back().val < A[row][j]) {
            que.pop_back();
        }
        que.push_back({ A[row][j], j });
        while (!que.empty() && j - que.front().id >= k) {
            que.pop_front();
        }
        A[row][j] = que.front().val;
    }
}
void getcol_maxi(int col)
{
    deque<node> que;
    for (int i = 1; i < k; i++) {
        while (!que.empty() && que.back().val < A[i][col]) {
            que.pop_back();
        }
        que.push_back({ A[i][col], i });
    }
    for (int i = k; i <= n; i++) {
        while (!que.empty() && que.back().val < A[i][col]) {
            que.pop_back();
        }
        while (!que.empty() && i - que.front().id >= k) {
            que.pop_front();
        }
        que.push_back({ A[i][col], i });
        A[i][col] = que.front().val;
    }
}
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            A[i][j] = lcm(i, j);
        }
    }
    for (int i = 1; i <= n; i++)
        getrow_maxi(i);
    for (int j = 1; j <= m; j++)
        getcol_maxi(j);
    ll ans = 0;
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            ans += A[i][j];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
