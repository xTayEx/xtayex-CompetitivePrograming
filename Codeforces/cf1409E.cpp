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
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF 0x3f3f3f3f
#define lson lef,mid,rt<<1
#define rson mid+1,rig,rt<<1|1
const int maxn=2e5+5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int x[maxn],y[maxn];
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        int n,k;scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&y[i]);
        }
    }
}
