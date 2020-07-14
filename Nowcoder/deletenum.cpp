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
const int maxn=1e6+5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    ll sum=0;
    int n;scanf("%d",&n);
    ll tmp;
    for(int i=1;i<=n;i++){
        scanf("%lld",&tmp);
        if(tmp<0) sum+=tmp*i;
        else sum+=tmp;
    }
    printf("%lld\n",sum);
    return 0;
}
