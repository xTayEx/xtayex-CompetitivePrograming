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
const int maxn=1e6+5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll f[maxn];
ll fAux[maxn];
const ll mod=998224353;
inline void init()
{
    f[1]=1;f[2]=2;
    fAux[1]=1;fAux[2]=2;
    for(int i=3;i<maxn;i++){
        f[i]=f[i-1]+f[i-2];
        fAux[i]=(fAux[i-1]%mod+fAux[i-2]%mod)%mod;
    }
}
int main()
{
    init();
    int T;scanf("%d",&T);
    int bit;
    while(T--){
        ll alen;ll A=0;
        scanf("%lld",&alen);
        for(int i=1;i<=alen;i++){
            scanf("%d",&bit);
            if(bit) A=(A%mod+f[i]%mod)%mod;
        }
        ll blen;ll B=0;
        scanf("%lld",&blen);
        for(int i=1;i<=blen;i++){
            scanf("%d",&bit);
            if(bit) B=(B%mod+f[i]%mod)%mod;
        }
        ll clen;ll C=0;
        scanf("%lld",&clen);
        for(int i=1;i<=clen;i++){
            scanf("%d",&bit);
            if(bit) C=(C%mod+f[i]%mod)%mod;
        }
        ll ans=(A%mod*B%mod)%mod;
        ll sub=ans-C;
        ll bnd=max(clen,alen+blen);
        int idx=lower_bound(fAux+1,fAux+1+bnd,)-fAux;
    }
    return 0;
}
