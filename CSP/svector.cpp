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
const int maxn = 5e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
map<int, int> mp;
int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int u, v;
    for (int i = 1; i <= a; i++) {
        scanf("%d%d", &u, &v);
        mp[u] = v;
    }
    ll sum = 0;
    map<int, int>::iterator it;
    for (int i = 1; i <= b; i++) {
        scanf("%d%d", &u, &v);
        if ((it = mp.find(u)) != mp.end()) {
            sum += 1LL * it->second * v;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
