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
const int mod = 998244353;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
string s, tmp, res;
ll fpow(ll a, ll b)
{
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a;
        a *= a, b >>= 1;
    }
    return ret;
}
string i2s(ll val)
{
    string ret = "";
    while (val) {
        ret.push_back('0' + val % 10);
        val /= 10LL;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
int nxt[maxn];
void getNext(string& p)
{
    nxt[0] = -1;
    int k = -1, j = 0;
    int sz = p.size();
    while (j < sz) {
        if (k == -1 || p[k] == p[j]) {
            j++, k++;
            nxt[j] = (p[k] != p[j] ? k : nxt[k]);
        } else {
            k = nxt[k];
        }
    }
}
int kmp(string& s, string& p)
{
    getNext(p);
    int i = 0, j = 0;
    int cnt = 0;
    int sz = s.size();
    while (i < sz) {
        if (j == -1 || s[i] == p[j]) {
            i++, j++;
        } else {
            j = nxt[j];
        }
        if (j >= 0 && !p[j]) {
            cnt = (cnt % mod + 1) % mod;
            j = 0;
        }
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n >> s;
    tmp = "1";
    string resstr;
    while (n--) {
        res.clear();
        int sz = tmp.size();
        for (int i = 0; i < sz; i++) {
            ll now = (tmp[i] - '0') * 1LL;
            ll Pow = fpow(2LL, now);
            resstr = i2s(Pow);
            res += resstr;
        }
        tmp = res;
    }
    int ans = kmp(res, s);
    cout << ans << "\n";
    return 0;
}
