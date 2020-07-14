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
const int maxn=1e4+5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int arr[maxn];
vector<int> ans;
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    stack<int> stk;
    for(int i=n;i>=1;i--){
        while(!stk.empty()&&arr[i]>=arr[stk.top()]){
            stk.pop();
        }
        if(stk.empty()){
            ans.push_back(0);
        }else{
            ans.push_back(stk.top());
        }
        stk.push(i);
    }
    reverse(ans.begin(),ans.end());
    int sz=ans.size();
    for(int i=0;i<sz;i++){
        printf("%d%c",ans[i],i==sz-1?'\n':' ');
    }
    return 0;
}
