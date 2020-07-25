
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
const int maxn = 8e5 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[maxn], b[maxn];
int p[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        b[i] = a[(i + n + p[1]) % n];
    }
    int ans = 0, lastpos = -2, lastval = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (b[i] != i + 1) {
            int pos;
            for (int j = 0; j < n; j++) {
                if (b[j] == i + 1) {
                    pos = j;
                    break;
                }
            }
            for (int j = pos; j < i; j++) {
                swap(b[j], b[j + 1]);
            }
            if (pos != lastpos - 1 || i + 1 != lastval - 1) {
                ans++;
            }
            lastpos = pos;
            lastval = b[i];
        }
    }
    cout << ans << endl;
    return 0;
}
/*
8
8 4 5 7 3 6 2 1
*/
