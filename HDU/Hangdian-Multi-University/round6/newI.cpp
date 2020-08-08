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
int digit[maxn];
bool solve(ll b,ll x)
{
    digit[0]=digit[1]=digit[2]=1;

}
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        ll b,x;scanf("%lld %lld",&b,&x);
        bool flag=solve(b,x);
        if(flag) puts("T");
        else puts("F");
    }
    return 0;
}
