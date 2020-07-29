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
const int maxn = 500 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int p[maxn];
int dp[maxn];
inline void init(int n)
{
    for (int i = 0; i <= n; i++) {
        dp[i] = 1;
    }
}
//inline void Debug(int len)
//{
//for(int i=1;i<=len;i++){
//printf("%d%c",p[i],i==len?'\n':' ');
//}
//}
int main()
{
    //freopen("./D.in", "r", stdin);
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &p[i]);
    }
    int maxi = 0;
    for (int k = 0; k < N; k++) {
        init(N);
        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j < i; j++) {
                if (p[i] > p[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxi = max(dp[N], maxi);
        //printf("maxi = %d\n",maxi);
        //Debug(N);
        rotate(p + 1, p + 2, p + 1 + N);
    }
    int ans = N - maxi;
    printf("%d\n", ans);
    return 0;
}
