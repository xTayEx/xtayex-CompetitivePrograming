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
const int maxn=50+5;
const int maxm=105;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int d[maxn];
int deg[maxn];
vector<int> G[maxn];
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&d[i]);
        }
        int ai,bi;
        for(int i=1;i<=m;i++){
            scanf("%d %d",&ai,&bi);
            G[ai].emplace_back(bi);
            G[bi].emplace_back(ai);
        }
        mst(deg,0);
        for(int i=1;i<=n;i++){
            int sz=G[i].size();
            int v;int maxi=-INF;
            for(int j=0;j<sz;j++){
                v=G[i][j];
                if(maxi<abs(deg[v]-deg[i])){
                    maxi=abs(deg[v]-deg[i]);
                }
            }
        }
    }
}
