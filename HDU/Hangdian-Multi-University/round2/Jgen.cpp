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
unordered_map<int,int> cnt;
int main()
{
    freopen("J.in","w",stdout);
    puts("10");
    for(int i=1;i<=10;i++){
        printf("50 50\n");
        cnt.clear();
        srand(time(0));
        for(int i=1;i<=50;i++){
            int type=rand()%50+1;
            while(cnt[type]){
                type=rand()%50+1;   
            }
            cnt[type]=1;
            printf("%d %d %d %d %d\n",type,rand()%100+1,rand()%100+1,rand()%100+1,rand()%100+1);
        }
    }
    return 0;
}
