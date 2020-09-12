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
int arr[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        //printf("n = %d\n",n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }
        sort(arr + 1, arr + n + 1);
        int sum = 1;
        for (int i = n; i > 0; i--) {
            if (arr[i] <= i) {
                sum += i;
                break;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
