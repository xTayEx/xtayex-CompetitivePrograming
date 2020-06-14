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
int a[maxn];
int b[maxn];
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        bool flag=1;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]<a[i-1]) flag=0;
        }
        int one=0;int zero=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            if(b[i]==1) one++;
            else zero++;
        }
        if(flag){
            puts("Yes");
            continue;
        }
        if(one>0&&zero>0) puts("Yes");
        else puts("No");
    }
    return 0;
}
