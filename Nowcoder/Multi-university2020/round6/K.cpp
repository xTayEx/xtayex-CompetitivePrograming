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
int rmost[maxn];
unordered_map<int, int> cnt;
int main()
{
    freopen("./Kgen.in","r",stdin);
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
        if (n <= k) {
            cnt.clear();
            flag = 1;
            for (int i = 1; i <= n; i++) {
                cnt[arr[i]]++;
                if (cnt[arr[i]] != 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                puts("YES");
            else
                puts("NO");
        } else {
            for (int i = 1; i <= n; i++) {
                int p = i;
                while (cnt[arr[p]] == 0 && p <= n) {
                    cnt[arr[p]]++;
                    p++;
                }
                rmost[i] = p - 1;
                //printf("i = %d, rmost[i] = %d\n",i,rmost[i]);
            }
            flag = 0;
            for (int i = 1; i <= rmost[1]; i++) {
                bool isstart = 1;
                for (int j = i + 1; j <= n; j += k) {
                    if (rmost[j] >= n)
                        break;
                    if (rmost[j] - j + 1 != k) {
                        //printf("j = %d\n",j);
                        isstart = 0;
                        break;
                    }
                }
                //printf("i = %d, isstart = %d\n",i,isstart);
                if (isstart) {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                puts("YES");
            else
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
