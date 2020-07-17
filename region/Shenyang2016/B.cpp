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
char s[15];
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        int ans=0;
        int n=strlen(s+1);
        for(int i=1;i<=n;i++){
            if(s[i]=='H') ans++;
            else if(s[i]=='C') ans+=12;
            else if(s[i]=='O') ans+=16;
        }
        printf("%d\n",ans);
    }
    return 0;
}
