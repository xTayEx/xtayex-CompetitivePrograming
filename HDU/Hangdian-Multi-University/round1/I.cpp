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
    ll a,p;
    bool operator<(const line& l)const{
        if(a!=l.a) return a>l.a;
        return p<l.p;
    }
    bool operator==(const line& l)const{
        return a==l.a&&p==l.p;
    }
};
line ls[50005];
line newls[5005];
int stk[50005];
double crossx(int idx1,int idx2)
{
    double up=1.0*(ls[idx2].p-ls[idx1].p);
    double down=1.0*(ls[idx1].a-ls[idx2].a);
    return up/down;
}
map<pll,bool> vis;
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        ll a,p;
        for(int i=1;i<=n;i++){
            scanf("%lld %lld",&a,&p);
            ls[i]={a,p};
        }
        sort(ls+1,ls+1+n);
        int idx=1;
        vis.clear();
        for(int i=1;i<=n;i++){
            pll pa=make_pair(ls[i].a, ls[i].p);
            if(vis.count(pa)==0){
                newls[idx++]=ls[i];
                vis[pa]=1;
            }
        }
        int Top=1;
        stk[Top++]=1;
        stk[Top++]=2;
        for(int i=3;i<=n;i++){
            while(Top>=3&&crossx(stk[Top-1],stk[Top-2])<crossx(stk[Top-1],i)) Top--;
            stk[Top++]=i;
        }
        printf("%d\n",Top-1);
    }
    return 0;
}
