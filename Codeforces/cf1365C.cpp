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
const int maxn=2e5+5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[maxn];int b[maxn];
int posa[maxn];
int posb[maxn];
int k[maxn];
int main()
{
    mst(k,0);
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        posa[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        posb[b[i]]=i;
    }
    for(int i=1;i<=n;i++){
        int pos1=posa[i];
        int pos2=posb[i];
        if(pos1<pos2){
            k[pos2-pos1]++;
        }else if(pos1>pos2){
            k[n-pos1+pos2]++;
        }else if(pos1==pos2){
            k[0]++;
        }
    }
    int ans=-1;
    for(int i=0;i<=n-1;i++){
        ans=max(ans,k[i]);
    }
    printf("%d\n",ans);
    return 0;
}
