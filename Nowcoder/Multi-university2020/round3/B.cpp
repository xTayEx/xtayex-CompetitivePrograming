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
const int maxn=1e5+5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char s[maxn];
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        scanf("%s",s+1);
        int ba=0;int ans=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'){
                if(i==1) continue;
                if(ba>0){
                    ba--;ans++;
                }
            }else if(s[i]=='1'){
                if(ba>0){
                    ba--;ans++;
                }
                ba++;
            }else if(s[i]=='2'){
                ans++;
            }else if(s[i]=='3'){
                ans++;ba++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
