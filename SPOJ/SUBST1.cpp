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
int sa[maxn],rk[maxn],oldrk[maxn];
int id[maxn];
int cnt[maxn];
int px[maxn];
bool cmp(int x,int y,int w)
{
    return oldrk[x]==oldrk[y]&&oldrk[x+w]==oldrk[y+w];
}
inline void getsa()
{
    mst(cnt,0);
    int len=strlen(s+1);
    int m=max(len,300);
    for(int i=1;i<=len;i++){
        rk[i]=s[i];
        cnt[rk[i]]++;
    }
    for(int i=1;i<=m;i++){
        cnt[i]+=cnt[i-1];
    }
    for(int i=len;i>=1;i--){
        sa[cnt[rk[i]]--]=i;
    }
    int w,p;
    for(w=1;w<len;w<<=1,m=p){
        int i;
        for(p=0,i=len;i>len-w;i--){
            id[++p]=i;
        }
        for(i=1;i<=len;i++){
            if(sa[i]>w){
                id[++p]=sa[i]-w;
            }
        }
        mst(cnt,0);
        for(i=1;i<=len;i++){
            px[i]=rk[id[i]];
            cnt[px[i]]++;
        }
        for(i=1;i<=m;i++){
            cnt[i]+=cnt[i-1];
        }
        for(i=len;i>=1;i--){
            sa[cnt[px[i]]--]=id[i];
        }
        memcpy(oldrk,rk,sizeof(rk));
        for(p=0,i=1;i<=len;i++){
            rk[sa[i]]=cmp(sa[i],sa[i-1],w)?p:++p;
        }
    }
}
int height[maxn];
void getheight(int len)
{
    int i,k;
    for(i=1,k=0;i<=len;i++){
        if(k) k--;
        while(s[i+k]==s[sa[rk[i]-1]+k]) k++;
        height[rk[i]]=k;
    }
}
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        int len=strlen(s+1);
        getsa();
        getheight(len);
        ll ans=0;
        for(int i=1;i<=len;i++){
            ans+=len-sa[i]+1-height[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
