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
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char s[maxn];
int cnt[10] = { 0 };
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        mst(cnt, 0);
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        for (int i = 1; i <= len; i++) {
            cnt[s[i] - '0']++;
        }
        int maxi = 0;
        for (int i = 0; i <= 9; i++) {
            maxi = max(maxi, cnt[i]);
        }
        int ans2 = 0;
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                int l=0;
                for(int k=1;k<=len;k++){
                    if(l%2==0){
                        if(s[k]==i+'0') l++;
                    }else{
                        if(s[k]==j+'0') l++;
                    }
                }
                if(l&1) l--;
                ans2=max(ans2,l);
            }
        }
        //printf("ans2 = %d\n", ans2);
        ans2 = len - ans2;
        int ans1 = len - maxi;
        printf("%d\n", min(ans2, ans1));
    }
    return 0;
}
