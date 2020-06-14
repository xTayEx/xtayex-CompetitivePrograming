#include <deque>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <cmath>
#include <unordered_map>
#define mst(a,b) memset((a),(b),sizeof(a))
#define debug printf("debug\n")
#define INF 0x3f3f3f3f
#define lson lef,mid,rt<<1
#define rson mid+1,rig,rt<<1|1
const int maxn=1e3+5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char str[maxn];
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        getchar();
        scanf("%s",str);
        int len=strlen(str);
        if(len<=2){
            puts("0");
        }else{
            int onecnt=0;int zerocnt=0;
            for(int i=0;i<len;i++){
                if(str[i]=='0') zerocnt++;
                else onecnt++;
            }
            int ans=INF;int tmp1,tmp2;
            int zerosum=0;int onesum=0;
            for(int i=0;i<len;i++){
                if(str[i]=='0') zerosum++;
                else onesum++;
                tmp1=zerosum+onecnt-onesum; // 111111...0000
                tmp2=onesum+zerocnt-zerosum; // 0000...111
                ans=min(ans,min(tmp1,tmp2));
            }
            // 以i作为分割处
            int mini=min(onecnt,zerocnt);
            ans=min(ans,mini);
            printf("%d\n",ans);
        }
    }
    return 0;
}
