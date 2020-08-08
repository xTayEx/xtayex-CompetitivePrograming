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
int a[maxn];
int pre[maxn], suf[maxn];
void show(int n)
{
    n += 5;
    puts("a:");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    puts("\npre:");
    for (int i = 1; i <= n; i++) {
        printf("%d ", pre[i]);
    }
    puts("\nsuf:");
    for (int i = 1; i <= n; i++) {
        printf("%d ", suf[i]);
    }
    puts("");
}
inline void init(int n)
{
    for (int i = 0; i <= n + 2; i++) {
        pre[i] = suf[i] = a[i] = 0;
    }
}
inline void show_a(int n)
{
    puts("this is a:");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    puts("");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        init(n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        if (n <= 2) {
            puts("0");
            continue;
        }
        int p = 1;
        int cnt = 0;
        while (p + 1 <= n) {
            while (p + 1 <= n && a[p + 1] - a[p] >= 0) {
                p++;
                cnt++;
            }
            pre[p] = cnt;
            p++, cnt = 0;
        }
        p = n;
        cnt = 0;
        while (p - 1 >= 1) {
            while (p - 1 >= 1 && a[p - 1] - a[p] >= 0) {
                p--;
                cnt++;
            }
            suf[p] = cnt;
            p--, cnt = 0;
        }
        //show(n);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (suf[i] == n - i) {
                //idebug(i);
                ans = i - pre[i] - 1;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
