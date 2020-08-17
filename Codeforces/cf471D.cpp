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
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int nxt[maxn];
int val;
void get_nxt(int* p, int len)
{
    nxt[0] = -1;
    int k = -1, j = 0;
    while (j < len) {
        if (k == -1 || p[k] == p[j]) {
            j++, k++;
            nxt[j] = k;
        } else {
            k = nxt[k];
        }
    }
}
int kmp(int* s, int lens, int* p, int lenp)
{
    get_nxt(p, lenp);
    int i = 0, j = 0;
    int cnt = 0;
    while (i < lens) {
        if (j == -1 || s[i] == p[j]) {
            i++, j++;
        } else {
            j = nxt[j];
        }
        if (j >= lenp) {
            cnt++, j = nxt[j];
        }
    }
    return cnt;
}
int a[maxn], b[maxn], a2[maxn], b2[maxn];
int main()
{
    int n, w;
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < w; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i + 1 < n; i++) {
        a2[i] = a[i + 1] - a[i];
    }
    for (int i = 0; i + 1 < w; i++) {
        b2[i] = b[i + 1] - b[i];
    }
    int ans;
    ans = (w == 1 ? n : kmp(a2, n - 1, b2, w - 1));
    printf("%d\n", ans);
    return 0;
}
