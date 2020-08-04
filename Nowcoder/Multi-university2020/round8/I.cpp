#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define debug printf("debug\n")
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 2e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int pre[maxn];
bool isr[maxn];
unordered_map<int, int> id;
inline void init(int n)
{
    for(int i=0;i<=2*n;i++){
        isr[i]=0;pre[i]=i;
    }
    id.clear();
}
int findr(int x)
{
    if(x==pre[x]) return x;
    return pre[x]=findr(pre[x]);
}
void merge(int x,int y)
{
    int fx=findr(x);
    int fy=findr(y);
    if(fx==fy){
        isr[fx]=isr[fy]=1;
    }else{
        pre[fx]=fy;
        isr[fy]=isr[fy]|isr[fx];
    }
}
int main()
{
    int T;scanf("%d",&T);
    int kase=0;
    while(T--){
        int N;scanf("%d",&N);
        init(N);
        int a,b;
        int cnt=0;
        for(int i=1;i<=N;i++){
            scanf("%d %d",&a,&b);
            if(!id[a]) id[a]=++cnt;
            if(!id[b]) id[b]=++cnt;
            merge(id[a],id[b]);
        }
        int ans=cnt;
        for(int i=1;i<=cnt;i++){
            if(pre[i]==i&&!isr[i]){
                ans--;
            }
        }
        printf("Case #%d: %d\n",++kase,ans);
    }
    return 0;
}
