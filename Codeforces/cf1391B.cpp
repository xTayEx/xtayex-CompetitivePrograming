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
char arr[105][105];
int n,m;
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        getchar();
        for(int i=1;i<=n;i++){
            scanf("%s",arr[i]+1);
        }
        int ans=0;
        for(int i=1;i<n;i++){
            if(arr[i][m]!='D') ans++;
        }
        for(int j=1;j<m;j++){
            if(arr[n][j]!='R') ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
