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
int main()
{
    string s;
    cin >> s;
    int len = s.size();
    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'w') ans++;
    }
    for (int i = 0; i + 1 < len; i++) {
        if (s[i] == 'w' && s[i + 1] == 'w') ans++;
    }
    printf("%d\n", ans);
    return 0;
}
