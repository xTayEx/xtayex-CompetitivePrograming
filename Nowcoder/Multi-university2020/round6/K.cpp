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
const int maxn = 5e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int arr[maxn];
int pre[maxn];
int suf[maxn];
unordered_map<int, int> cnt;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d %d", &n, &k);
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            if (arr[i] > k || arr[i] < 1) {
                flag = 0;
            }
        }
        if (!flag) {
            puts("NO");
            continue;
        }
        if (n < k) {
            puts("YES");
            continue;
        }
        pre[0] = suf[n + 1] = 0;
        cnt.clear();
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1];
            if (cnt[arr[i]] == 0) {
                pre[i]++;
            }
            cnt[arr[i]]++;
        }
        cnt.clear();
        for (int i = n; i >= 1; i--) {
            suf[i] = suf[i + 1];
            if (cnt[arr[i]] == 0) {
                suf[i]++;
            }
            cnt[arr[i]]++;
        }
        int lef = 1;
        int rig = n;
        while (lef <= n && pre[lef] == lef)
            lef++;
        while (rig >= 1 && suf[rig] == n - rig + 1)
            rig--;
        cnt.clear();
        for (int i = lef; i <= rig; i++) {
            printf("arr[i] = %d\n",arr[i]);
            printf("cnt[arr[i]] = %d\n",cnt[arr[i]]);
            cnt[arr[i]]++;
        }
        int mini = INF;
        int maxi = 0;
        for(auto& it:cnt){
            mini=min(mini,it.second);
            maxi=max(maxi,it.second);
        }
        printf("lef = %d, rig = %d, mini = %d, maxi = %d\n", lef, rig, mini, maxi);
        cnt.clear();
        int len = rig - lef + 1;
        if (len % k == 0 && maxi == mini) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
/*
 * 
 * 8 3
 * 2 3 1 2 3 1 2 3 （"YES")
 */
