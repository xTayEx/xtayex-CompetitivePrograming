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
int d[105];
inline void draw(int s,int maxi,int idx)
{
    printf("+");
    for(int i=1;i<=s;i++) printf("-");
    printf("+\n");
    printf("|");
    for(int i=1;i<=s;i++){
        if(i==s) printf("%c",d[idx]==maxi?'*':' ');
        else printf(" ");
    }
    printf("|%d\n",d[idx]);
    printf("+");
    for(int i=1;i<=s;i++) printf("-");
    printf("+\n");
}
int main()
{
    int n;scanf("%d",&n);
    int  maxi=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&d[i]);
        maxi=max(maxi,d[i]);
    }
    int s;
    for(int i=1;i<=n;i++){
        s=ceil(50*(1.0*d[i])/(maxi*1.0));
        draw(s,maxi,i);
    }
    return 0;
}
