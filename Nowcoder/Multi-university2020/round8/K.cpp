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
typedef __int128 ll;
typedef unsigned long long ull;
ll a[maxn], b[maxn];
ll read()
{
    char ch;
    ll s = 1;
    do {
        ch = getchar();
        if (ch == '-')
            s = -1;
    } while (ch > '9' || ch < '0');
    ll ret = 0;
    while (ch >= '0' && ch <= '9') {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    return ret * s;
}
void write(ll x)
{
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
void writeLn(ll x)
{
    write(x), puts("");
}
ll pre[maxn];
struct node {
    ll val;
    int id;
    bool operator<(const node& nn) const
    {
        return val < nn.val;
    }
};
priority_queue<node> pq;
int main()
{
    int kase = 0;
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        pre[0] = 0;
        while (!pq.empty())
            pq.pop();
        for (int i = 1; i <= n; i++) {
            a[i] = read();
            pre[i] = pre[i - 1] + a[i];
            pq.push({ pre[i], i });
        }
        ll ges;
        b[1] = read(), ges = b[1];
        for (int i = 2; i <= n; i++) {
            b[i] = read();
            b[i] = min(b[i], b[i - 1]);
        }
        ll ans = 0;
        ll base = 0;
        while (!pq.empty()) {
            node now = pq.top();
            pq.pop();
            int idx = now.id;
            if (base < b[idx]) {
                ans += now.val * (b[idx] - base);
                base += (b[idx] - base);
            }
        }
        printf("Case #%d: ", ++kase), write(ges), printf(" "), write(ans), puts("");
    }
    return 0;
}
