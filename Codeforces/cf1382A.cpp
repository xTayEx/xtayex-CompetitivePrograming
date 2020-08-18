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
#define idebug(x) printf("%s = %d\n",#x,x)
#define ddebug(x) printf("%s = %lf\n",#x,x)
#define INF 0x3f3f3f3f
#define lson lef,mid,rt<<1
#define rson mid+1,rig,rt<<1|1
const int maxn=1e5+5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
set<int> a,b;
int cnt[1005];
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        a.clear(),b.clear();
        int n,m;scanf("%d%d",&n,&m);
        int tmp;
        for(int i=1;i<=n;i++){
            scanf("%d",&tmp),a.insert(tmp);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&tmp),b.insert(tmp);
        }
        mst(cnt,0);
        for(auto& it:a){
            cnt[it]++;
        }
        for(auto& it:b){
            cnt[it]++;
        }
        int ans=-1;
        for(int i=1;i<=1000;i++){
            if(cnt[i]>=2){
                ans=i;
                break;
            }
        }
        if(ans==-1){
            puts("NO");
        }else{
            puts("YES");
            printf("1 %d\n",ans);
        }
    }
    return 0;
}
