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
char s[maxn];
int main()
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++){
        s[i]=tolower(s[i]);
    }
    string tmps="";
    for(int i=1;i<=min(6,len);i++){
        tmps.push_back(s[i]);
    }
    if(tmps=="lovely"){
        puts("lovely");
    }else{
        puts("ugly");
    }
    return 0;
}
