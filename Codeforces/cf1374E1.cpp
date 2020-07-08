
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
#include <limits>
#define mst(a,b) memset((a),(b),sizeof(a))
#define debug printf("debug\n")
#define INF 0x3f3f3f3f
#define lson lef,mid,rt<<1
#define rson mid+1,rig,rt<<1|1
const int maxn=2e5+5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct node{
    ll t;
    int a;
    int b;
    bool operator<(const node& nn)const{
        return t<nn.t;
    }
};
node allone[maxn];
node A[maxn];
node B[maxn];
ll sum1[maxn];
ll sum2[maxn];
ll sum3[maxn];
unordered_map<int, bool> mp;
int main()
{
    mp.clear();
    int n,k;scanf("%d %d",&n,&k);
    int idx1,idx2,idx3;
    idx1=idx2=idx3=1;
    ll t_;int a_,b_;
    for(int i=1;i<=n;i++){
        scanf("%lld %d %d",&t_,&a_,&b_);
        if(a_&&b_) allone[idx1++]={t_,a_,b_};
        if(a_&&!b_) A[idx2++]={t_,a_,b_};
        if(!a_&&b_) B[idx3++]={t_,a_,b_};
    }
    sort(allone+1,allone+idx1);
    sort(A+1,A+idx2);
    sort(B+1,B+idx3);
    for(int i=1;i<=n;i++){
        sum1[i]=sum1[i-1]+allone[i].t;
        sum2[i]=sum2[i-1]+A[i].t;
        sum3[i]=sum3[i-1]+B[i].t;
    }
    ll inf=numeric_limits<ll>::max();
    ll ans=inf;
    for(int i=0;i<=min(k,idx1-1);i++){
        int tmp=k-i;
        if(idx2-1>=tmp&&idx3-1>=tmp){
            ans=min(ans,sum1[i]+sum2[k-i]+sum3[k-i]);
        }
    }
    if(ans==inf){
        puts("-1");
    }else{
        printf("%lld\n",ans);
    }
    return 0;
}
