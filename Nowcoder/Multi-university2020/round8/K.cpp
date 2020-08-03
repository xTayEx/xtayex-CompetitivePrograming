
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
const int maxn = 2e5 + 7;
using namespace std;
typedef __int128 ll;
//typedef unsigned long long ull;
ll sum[maxn];
ll n;
struct Node {
    ll b, p;
    ll a;
    int operator<(const Node& b) const
    {
        if (a == b.a)
            return p > b.p;
        return a > b.a;
    }
} node[maxn];
stack<ll> s;
vector<ll> v;
ll read()
{
    ll s = 1;
    ll x = 0;
    char ch;
    do {
        ch = getchar();
        if (ch == '-')
            s = -1;
    } while (ch > '9' || ch < '0');
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * s;
}
void write(ll val)
{
    if (val < 0) {
        putchar('-');
        val = -val;
    }
    if (val > 9)
        write(val / 10);
    putchar(val % 10 + '0');
}
int main()
{
    int t;
    cin >> t;
    node[0].a = node[0].b = node[0].p = 0;
    for (int T = 1; T <= t; T++) {
        n = read();
        for (ll i = 1; i <= n; i++) {
            ll a;
            a = read();
            node[i].a = node[i - 1].a + a;
        }
        for (ll i = 1; i <= n; i++) {
            node[i].b = read();
            node[i].p = i;
            if (i != 1)
                node[i].b = min(node[i - 1].b, node[i].b);
        }
        while (!s.empty()) {
            s.pop();
        }
        v.clear();
        for (ll i = n; i >= 1; i--) {
            while (!s.empty()) {
                ll l = s.top();
                if (node[i].a >= node[l].a) {
                    s.pop();
                } else
                    break;
            }
            s.push(i);
        }
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }
        ll ans = 0;
        for (ll i = v.size() - 1; i >= 0; i--) {
            if (i == v.size() - 1) {
                ans += node[v[i]].a * node[v[i]].b;
            } else
                ans += node[v[i]].a * (node[v[i]].b - node[v[i + 1]].b);
        }
        printf("Case #%d: ", T);
        write(node[1].b);
        printf(" ");
        write(ans);
        puts("");
        //cout << "Case #" << T << ": ";
        //cout << node[1].b << " " << ans << endl;
    }
    return 0;
}
