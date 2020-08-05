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
int arr[] = { 6, 10, 14, 15 };
void solve(int x)
{
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                int sub = x - arr[i] - arr[j] - arr[k];
                if (arr[i] + arr[j] + arr[k] < x && sub != arr[i] && sub != arr[j] && sub != arr[k]) {
                    puts("YES");
                    printf("%d %d %d %d\n", arr[i], arr[j], arr[k], x - arr[i] - arr[j] - arr[k]);
                    return;
                }
            }
        }
    }
    puts("NO");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        solve(n);
    }
    return 0;
}
