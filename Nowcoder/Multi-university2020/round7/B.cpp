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
typedef long long ll;
typedef unsigned long long ull;
vector<int> ansvec;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (n < m)
            swap(n, m);
        ansvec.clear();
        while (m != 0) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n / m; j++) {
                    ansvec.emplace_back(m);
                }
            }
            int tmp = n % m;
            n = m, m = tmp;
        }
        printf("%d\n", (int)ansvec.size());
        int siz = ansvec.size();
        for (int i = 0; i < siz; i++) {
            printf("%d%c", ansvec[i], i == siz - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
