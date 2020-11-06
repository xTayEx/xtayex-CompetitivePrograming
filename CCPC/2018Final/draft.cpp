
#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 1e5 + 5;
typedef long long ll;
int T;
struct node{
    int d, t;
}a[maxn];
 
bool cmp(node A, node B){
    if (A.d == B.d) return A.t < B.t;
    return A.d < B.d;
}
int n , m;
int main()
{
    scanf("%d", &T);
    for (int t = 0; t < T; t++){
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i].d);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i].t);
        sort(a, a + n, cmp);
        ll sum = 0, ans = -1;
        for (int i = 0; i < n; i++){
            if (sum + a[i].t <= m){
                sum += a[i].t;
            }else {
                ans = i;
                break;
            }
        }
        if (ans == -1) ans = n;
        printf("Case %d: %lld\n", t+1, ans);
    }
 
return 0;
