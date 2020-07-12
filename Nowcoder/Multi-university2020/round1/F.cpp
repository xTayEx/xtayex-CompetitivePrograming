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
int main()
{
    string sa, sb;
    std::ios::sync_with_stdio(0);
    while (cin >> sa >> sb) {
        int lena = sa.size();
        int lenb = sb.size();
        //sa+=sa;sb+=sb;
        int bnd = 2 * max(lena, lenb);
        int ans = 0;
        for (int i = 0; i < bnd; i++) {
            if (sa[i % lena] < sb[i % lenb]) {
                ans = 1; // <
                break;
            } else if (sa[i % lena] > sb[i % lenb]) {
                ans = 2; // >
                break;
            }
        }
        cout << "=<>"[ans] << "\n";
    }
    return 0;
}
