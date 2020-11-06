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
#define debug(x) cerr << "\033[01;31m" << #x << " = " << x << "\033[0m" \
                      << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
map<string, int> mp;
string s, a, b;
int main()
{
    mp["London"] = 0;
    mp["Moscow"] = 3;
    mp["Washington"] = -5;
    mp["Beijing"] = 8;
    int T;
    scanf("%d", &T);
    int kase = 0;
    while (T--) {
        s.clear();
        int h, m;
        scanf("%d:%d", &h, &m);
        cin >> s;
        if (s == "AM" && h == 12) h = 0;
        if (s == "PM" && h != 12) h += 12;
        a.clear(), b.clear();
        cin >> a >> b;
        int gap = mp[b] - mp[a];
        h += gap;
        debug(gap);
        cout << "Case " << ++kase << ": ";
        if (h < 0) {
            cout << "Yesterday ";
            h += 24;
        } else if (h > 23) {
            cout << "Tomorrow ";
            h -= 24;
        } else {
            cout << "Today ";
        }
        //debug(h);
        if (1 <= h && h <= 11) {
            printf("%d:%02d AM\n", h, m);
        } else if (13 <= h && h <= 23) {
            printf("%d:%02d PM\n", h - 12, m);
        } else if (h == 0) {
            printf("12:%02d AM\n", m);
        } else if (h == 12) {
            printf("12:%02d PM\n", m);
        }
    }
    return 0;
}
