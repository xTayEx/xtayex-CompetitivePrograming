#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define debug printf("debug\n")
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 2e6 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;scanf("%d",&n);
        int ba=0,ans=0;int tmp;
        for(int i=0;i<n;i++){
            scanf("%1d",&tmp);
            if(tmp==2||tmp==3) ans++;
            else if(tmp==1) ba++;
            else{
                if(ba>0) ba--,ans++;
            }
        }
        printf("%d\n",ans+ba/2);
    }
    return 0;
}
