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
const int maxn = 1e3 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
vector<int> ansvec;
int main()
{
    //cin.tie(0);
    //cout.tie(0);
    //ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n < m)
            swap(n, m);
        int k = n - m;
        int cnt = m * (k / m + 1);
        int res = 0;
        int p = 0;
        if (k >= m)
            k = k % m;
        if (k) {
            res = m / k * k;
            p = m % k;
        }
        int res2 = 0;
        if (p)
            res2 = (m - res) * (k / p);
        cout << cnt + res + res2 << "\n";
        ansvec.clear();
        for (int i = 1; i <= cnt; i++) {
            //cout << m << " ";
            ansvec.emplace_back(m);
        }
        for (int i = 1; i <= res; i++) {
            //cout << k << " ";
            ansvec.emplace_back(k);
        }
        for (int i = 1; i <= res2; i++) {
            ansvec.emplace_back(p);
        }
        int siz = ansvec.size();
        for (int i = 0; i < siz; i++) {
            cout << ansvec[i] << (i == siz - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
