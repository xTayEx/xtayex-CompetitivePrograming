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
const int maxn = 1e3 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int sg[maxn], s[maxn];
inline void getsg(int n)
{
    mst(sg, 0);
    for (int i = 1; i <= n; i++) {
        mst(s, 0);
        for (int j = 1; j <= i && j < maxn; j <<= 1) {
            s[sg[i - j]] = 1;
        }
        for (int j = 0;; j++) {
            if (!s[j]) {
                sg[i] = j;
                break;
            }
        }
    }
}
int main()
{
    int n;
    getsg(maxn);
    while (scanf("%d", &n) != EOF) {
        if(sg[n]) puts("Kiki");
        else puts("Cici");
    }
    return 0;
}
