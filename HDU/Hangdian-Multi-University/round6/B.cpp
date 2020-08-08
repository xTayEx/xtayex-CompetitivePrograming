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
char s[20];
bool isop(char ch)
{
    return (ch=='+'||ch=='-'||ch=='*'||ch=='/');
}
int main()
{
    while(scanf("%s",s+1)!=EOF){
        int p=1;
        string tmp="";
        while(!isop(p)){
            tmp.push_back(s[p]);
            p++;
        }
        int optype;
        if(s[p]=='+') optype=1;
        else if(s[p]=='-') optype=2;
        else if(s[p]=='*') optype=3;
        else if(s[p]=='/') optype=4;
    }
}
