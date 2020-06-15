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
char mp[55][55];
bool arr[55][55]; // block
bool vis[55][55];
int n,m;
bool check(int row,int col)
{
    if(arr[row][col]||vis[row][col]||row<1||row>n||col<1||col>m)
        return 0;
    return 1;
}
void dfs(int row,int col)
{
    if(!check(row,col)) return ;
    vis[row][col]=1;
    dfs(row+1,col);dfs(row-1,col);
    dfs(row,col+1);dfs(row,col-1);
}
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        mst(arr,0);mst(vis, 0);
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%s",mp[i]+1);
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j]=='B'){
                    arr[i][j]=1;
                    arr[i-1][j]=arr[i+1][j]=arr[i][j-1]=arr[i][j+1]=1;
                }else if(mp[i][j]=='#'){
                    arr[i][j]=1;
                }else if(mp[i][j]=='G'){
                    cnt++;
                }
            }
        }
        if(arr[n][m]){
            if(mp[n][m]=='B'){
                puts("No");
            }else{
                if(cnt==0) puts("Yes");
                else puts("No");
            }
            continue;
        }
        dfs(n,m);bool flag=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j]=='G'&&vis[i][j]==0){
                    flag=0;
                }
            }
        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
