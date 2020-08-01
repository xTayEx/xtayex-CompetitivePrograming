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
int main()
{
    int T;
    for(int i=1;i<=40000;i++){
        ll n=i;
        __int128 sum=(n*(n+1)*(2*n+1))/6;
        ll sq=sqrt(sum);
        double sqd=sqrt(1.0*sum);
        if(fabs(sq*1.0-sqd)<=1e-5){

            printf("%lld\n",n);
        }
    }
    return 0;
}
