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
#define debug(x) cerr << "\033[01;31m" << #x << " = " << x << "\033[0m" << "\n"
#define INF 0x3f3f3f3f
#define lson lef,mid,rt<<1
#define rson mid+1,rig,rt<<1|1
const int maxn=1e6 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char s[maxn], t[maxn];
vector<int>v[2];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s %s", s, t);
        v[0].clear(),v[1].clear();
        int p1 = 0, p2 = 0;
        if (strlen(s) != strlen(t)) {
            puts("-1");
            continue;
        }
        ll ans = 0;
        for (int i = 0; s[i]; ++i) {
            if (s[i] == '1') v[0].push_back(i);
            if (t[i] == '1') v[1].push_back(i);
        }
        if(v[0].size()!=v[1].size()){
            puts("-1");
            continue;
        }
        for(int i=0;i<v[0].size();i++){
            ans+=abs(v[0][i]-v[1][i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
