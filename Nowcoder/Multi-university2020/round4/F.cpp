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
    int T;scanf("%d",&T);
    while(T--){
        int ac,ad,bc,bd;
        scanf("%d %d %d %d",&ac,&ad,&bc,&bd);
        printf("%s\n",ac+bd<ad+bc?"AB//CD":"AB//DC");
    }
    return 0;
}
