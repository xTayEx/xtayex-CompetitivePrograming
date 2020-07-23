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
#include <utility>
#include <unordered_map>
#define mst(a,b) memset((a),(b),sizeof(a))
#define debug printf("debug\n")
#define INF 0x3f3f3f3f
#define lson lef,mid,rt<<1
#define rson mid+1,rig,rt<<1|1
const int maxn=1e5+5;
using namespace std;
using pll = pair<long long,long long>;
typedef long long ll;
typedef unsigned long long ull;
struct line{
    ll p,a;
    bool operator<(const line& l)const{
        if(a!=l.a) return a>l.a;
        return p>l.p;
    }
    ll cnt;
};
line ls[50005];
int stk[50005<<1];
double crossx(int idx1,int idx2)
{
    double up=1.0*(ls[idx2].p-ls[idx1].p);
    double down=1.0*(ls[idx1].a-ls[idx2].a);
    return up/down;
}
map<pll,int> vis;
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        vis.clear();
        int n;scanf("%d",&n);
        ll p,a;
        ll  maxi=0;
        int idx=0;
        for(int i=1;i<=n;i++){
            scanf("%lld %lld",&p,&a);
            maxi=max(maxi,p);
            pll pa={p,a};
            if(vis[pa]==0){
                idx++;
                ls[idx]={p,a,1};
                vis[pa]=idx;
            }else{
                ls[vis[pa]].cnt++;
            }
        }
        int Top=1;
        ls[++idx]={maxi,-1,1};
        //printf("idx = %d\n",idx);
        sort(ls+1,ls+1+idx);
        stk[Top++]=1;
        for(int i=2;i<=idx;i++){
            if(ls[i].a==ls[i-1].a) continue;
            while(Top>=3&&crossx(stk[Top-1], stk[Top-2])-crossx(stk[Top-1],i)<=1e-8){
                //printf("ls[stk[Top-1]].p = %lld ls[stk[Top-1]].a = %lld\n",ls[stk[Top-1]].p,ls[stk[Top-1]].a);
                //printf("ls[stk[Top-2]].p = %lld ls[stk[Top-2]].a = %lld\n",ls[stk[Top-2]].p,ls[stk[Top-2]].a);
                //printf("ls[i].p = %lld ls[i].a = %lld\n",ls[i].p,ls[i].a);
                Top--;
            }
            stk[Top++]=i;
            //printf("i = %d, Top = %d\n",i,Top);
        }
        //printf("Top = %d\n",Top);
        ll ans=0;
        for(int i=1;i<Top;i++){
            if(ls[stk[i]].cnt<2){
                ans++;
            }
        }
        printf("%lld\n",ans-1);
    }
    return 0;
}
