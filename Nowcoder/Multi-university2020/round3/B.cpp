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
const int maxn=2e6+5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char s[maxn];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int q;scanf("%d",&q);
    int p=0;
    while(q--){
        char op[2];int x;
        scanf("%s %d",op,&x);
        if(op[0]=='M'){
            if(x>0){
                p=(p+x)%len;
            }else{
                x=abs(x);
                p-=x;
                p=(p%len+len)%len;
            }
        }else if(op[0]=='A'){
            x--;
            printf("%c\n",s[(p+x)%len]);
        }
    }
    return 0;
}
