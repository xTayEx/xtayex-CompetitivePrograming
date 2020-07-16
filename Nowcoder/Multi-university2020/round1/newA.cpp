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
int wa[maxn], wb[maxn], wv[maxn], wss[maxn], rak[maxn], height[maxn], cal[maxn], n, sa[maxn << 1];
char s[maxn];
int cmp(int* r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}
void da(int* r, int* sa, int n, int M)
{
    int i, j, p, *x = wa, *y = wb, *t;
    for (i = 0; i < M; i++)
        wss[i] = 0;
    for (i = 0; i < n; i++)
        wss[x[i] = r[i]]++;
    for (i = 1; i < M; i++)
        wss[i] += wss[i - 1];
    for (i = n - 1; i >= 0; i--)
        sa[--wss[x[i]]] = i;
    for (j = 1, p = 1; p < n; j <<= 1, M = p) {
        for (p = 0, i = n - j; i < n; i++)
            y[p++] = i;
        for (i = 0; i < n; i++)
            if (sa[i] >= j)
                y[p++] = sa[i] - j;
        for (i = 0; i < n; i++)
            wv[i] = x[y[i]];
        for (i = 0; i < M; i++)
            wss[i] = 0;
        for (i = 0; i < n; i++)
            wss[wv[i]]++;
        for (i = 1; i < M; i++)
            wss[i] += wss[i - 1];
        for (i = n - 1; i >= 0; i--)
            sa[--wss[wv[i]]] = y[i];
        for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
    return;
}
int main()
{
    //freopen("./A.in", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        fill(cal, cal + maxn, 0);
        scanf("%s", s + 1);
        int pre[2] = { n + 1, n + 1 };
        for (int i = n; i >= 1; i--) {
            if (pre[s[i] - 'a'] == n + 1) {
                cal[i] = n;
            } else {
                cal[i] = pre[s[i] - 'a'] - i;
            }
            pre[s[i] - 'a'] = i;
        }
        cal[n + 1] = n + 1;
        //puts("cal: ");
        //for (int i = 1; i <= n + 1; i++) {
        //  printf("%d ",cal[i]);
        //}
        //puts("");
        //puts("----------------------");

        da(cal + 1, sa, n + 2, n + 2);
        for (int i = n; i >= 1; i--) {
            printf("%d%c", sa[i] + 1, i == 1 ? '\n' : ' ');
        }
    }
    return 0;
}
