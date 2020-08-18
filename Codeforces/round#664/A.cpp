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
int arr[5];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3]);
        int zero=0;
        int odd=0,eve=0;
        int mini=INF;
        for(int i=0;i<3;i++){
            mini=min(mini,arr[i]);
        }
        for(int i=0;i<4;i++){
            if(arr[i]&1) odd++;
            else eve++;
        }
        if(odd<=1){
            puts("Yes");
            continue;
        }
        if(mini==0){
            puts("No");
            continue;
        }
        if(odd==2){
            puts("No");
        }else{
            puts("Yes");
        }
    }
    return 0;
}
