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
const int maxn=1e5+5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int arr[maxn];
int sum1[maxn][33];
int sum0[maxn][33];
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    for(int j=0;j<31;j++){
        for(int i=1;i<=n;i++){
            if(arr[i]&(1<<j)){
                sum1[i][j]=sum1[i-1][j]+1;
                sum0[i][j]=sum0[i-1][j];
            }else{
                sum1[i][j]=sum1[i-1][j];
                sum0[i][j]=sum0[i-1][j]+1;
            }
        }
    }
    //for(int i=0;i<8;i++){
        //printf("sum1[4][%d] = %d\n",i,sum1[4][i]);
        //printf("sum0[4][%d] = %d\n",i,sum0[4][i]);
        //puts("----------------------------------");
    //}
    int q;scanf("%d",&q);
    while(q--){
        int L,R;
        int ans=0;
        scanf("%d %d",&L,&R);
        for(int j=0;j<31;j++){
            int s1=sum1[R][j]-sum1[L-1][j];
            int s0=sum0[R][j]-sum0[L-1][j];    
            if(s1<s0) ans|=(1<<j);
        }
        printf("%d\n",ans);
    }
    return 0;
}
