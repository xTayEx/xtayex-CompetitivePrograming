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

bool same(int* rk, int idx1, int idx2, int len)
{
    return rk[idx1] == rk[idx2] && rk[idx1 + len] == rk[idx2 + len];
}
void SA(int* s, int* sa, int* sa2, int* rk, int* cnt, int n, int m)
{
    //counting sort
    for (int i = 0; i < m; i++)
        cnt[i] = 0;
    for (int i = 0; i < n; i++)
        cnt[rk[i] = s[i]]++;
    for (int i = 1; i < m; i++)
        cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--)
        sa[--cnt[rk[i]]] = i; //stable sort

    for (int len = 1; len <= n; len <<= 1) {
        int p = 0;
        for (int i = n - len; i < n; i++)
            sa2[p++] = i; 
        for (int i = 0; i < n; i++)
            if (sa[i] >= len)
                sa2[p++] = sa[i] - len;

        for (int i = 0; i < m; i++)
            cnt[i] = 0;
        for (int i = 0; i < n; i++)
            cnt[rk[sa2[i]]]++;
        for (int i = 1; i < m; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            sa[--cnt[rk[sa2[i]]]] = sa2[i];
        swap(rk, sa2);
        p = 1;
        rk[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            bool flag = same(sa2, sa[i - 1], sa[i], len);
            if(flag) rk[sa[i]] = p - 1;
            else rk[sa[i]] = p++;
        }
        if (p >= n)
            break;
        m = p;
    }
}
int cal[maxn], sa[maxn], sa2[maxn], rk[maxn], cnt[maxn];
char s[maxn];
int main()
{
    //freopen("./A.in", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF) {
        mst(cal, 0), mst(sa, 0);
        scanf("%s", s);
        int pre[2] = { n + 1, n + 1 };
        for (int i = n - 1; i >= 0; i--) {
            if (pre[s[i] - 'a'] == n + 1) {
                cal[i] = n;
            } else {
                cal[i] = pre[s[i] - 'a'] - i;
            }
            pre[s[i] - 'a'] = i;
        }
        cal[n] = n + 1;
        //puts("cal: ");
        //for (int i = 1; i <= n + 1; i++) {
        //  printf("%d ",cal[i]);
        //}
        //puts("");
        //puts("----------------------");

        SA(cal, sa, sa2, rk, cnt, n + 1, n + 2);
        for (int i = n - 1; i >= 0; i--) {
            printf("%d%c", sa[i] + 1, i == 0 ? '\n' : ' ');
        }
    }
    return 0;
}
