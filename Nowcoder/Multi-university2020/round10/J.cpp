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
#define idebug(x) printf("%s = %d\n", #x, x)
#define ddebug(x) printf("%s = %lf\n", #x, x)
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int p1[505],p2[505];
vector<int> graph[505];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p1[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&p2[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (p1[i] != 0) {
            graph[i].emplace_back(p1[i]);
            graph[p1[i]].emplace_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(p2[i]!=0){
            
        }
    }
}
