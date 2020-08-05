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
        int n;scanf("%d",&n);
        if(n<4){
            for(int i=0;i<n-1;i++){
                printf("9");
            }
            printf("8");
            puts("");
        }else if(n==4){
            puts("9990");
        }else{
            for(int i=0;i<n-2;i++){
                printf("9");
            }
        }
    }
}
