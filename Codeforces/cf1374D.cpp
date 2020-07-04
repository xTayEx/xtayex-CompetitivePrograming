#include <functional>
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
ll arr[maxn<<1];
map<ll,int> mp;
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        ll n,k;mp.clear();
        scanf("%lld %lld",&n,&k);
        bool flag=1;
        for(ll i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
            if(arr[i]%k!=0){
                flag=0;
            }
        }
        if(flag){
            puts("0");
        }else{
            int maxi=-1;
            for(int i=1;i<=n;i++){
                if(arr[i]%k==0) continue;
                mp[k-arr[i]%k]++;
                maxi=max(maxi,mp[k-arr[i]%k]);
            }
            map<ll,int>::iterator it;
            ll ans;
            for(it=mp.begin();it!=mp.end();it++){
                if(it->second==maxi){
                    ans=k*(it->second-1)+it->first+1;
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
