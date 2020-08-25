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
const int maxn=1e5+5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    int n;scanf("%d",&n);
    int cnt=n;
    int initcnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            printf(" ");
        }
        for(int j=1;j<=cnt;j++){
            printf("*");
            if(i==n) initcnt++;
        }
        int spccnt=1+2*(n-i);
        for(int j=1;j<=spccnt;j++){
            printf(" ");
            if(i==n) initcnt++;
        }
        for(int j=1;j<=cnt;j++){
            printf("*");
            if(i==n) initcnt++;
        }
        puts("");
        cnt+=2;
    }
    initcnt+=2;
    while(initcnt){
        for(int i=1;i<=initcnt;i++){
            printf("*");
        }
        puts("");
        initcnt-=2;
    }
    return 0;
}
