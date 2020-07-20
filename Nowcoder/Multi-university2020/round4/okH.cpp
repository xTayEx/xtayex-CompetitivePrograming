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
#include <utility>
#define mst(a,b) memset((a),(b),sizeof(a))
#define debug printf("debug\n")
#define INF 0x3f3f3f3f
#define lson lef,mid,rt<<1
#define rson mid+1,rig,rt<<1|1
const int maxn=2e5+5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int maxiPfact[maxn];
int id[maxn];
using pii = pair<int,int>;
inline void init()
{
    int idx=0;
    for(int i=2;i<=maxn;i++){
        if(maxiPfact[i]==0){
            id[i]=idx++;
            for(int j=i;j<=maxn;j+=i){
                maxiPfact[j]=i;
            }
        }
    }
}
vector<int> group[maxn];
vector<pii> ans; 
int main()
{
    int T;scanf("%d",&T);
    init();
    while(T--){
        ans.clear();
        int n;scanf("%d",&n);
        int bnd=0;
        for(int i=2;i<=n;i++){
            group[id[maxiPfact[i]]].push_back(i);
            bnd=max(bnd,maxiPfact[i]);
        }
        int bndidx=id[bnd];
        for(int i=bndidx;i>0;i--){
            int sz=group[i].size();
            if(sz%2==0){
                for(int j=0;j+1<sz;j+=2){
                    ans.push_back({group[i][j],group[i][j+1]});
                } 
            }else if(sz%2!=0&&sz!=1){
                group[0].push_back(group[i][1]); // 2 * p
                ans.push_back({group[i][0],group[i][2]});
                for(int j=3;j+1<sz;j+=2){
                    ans.push_back({group[i][j],group[i][j+1]});
                }
            }
        }
        int sz1=group[0].size();
        for(int i=0;i+1<sz1;i+=2){
            ans.push_back({group[0][i],group[0][i+1]});
        }
        for(int i=0;i<=bndidx;i++){
            group[i].clear();
        }
        printf("%d\n",(int)ans.size());
        for(auto& item:ans){
            printf("%d %d\n",item.first,item.second);
        }
    }
    return 0;
}
