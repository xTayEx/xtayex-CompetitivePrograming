#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    int n;
    cin>>t;
    while(t--){
    	ll r,g,b,w;
    	cin>>r>>g>>b>>w;
    	ll x=min(r,min(g,b));
    	int f=0;
    	if(r&1)f++;
    	if(g&1)f++;
    	if(b&1)f++;
    	if(w&1)f++;
 
    	if(f<=1){
    		cout<<"YES"<<endl;
    		continue;
    	}
    	if(x==0){//说明不能转变
    		cout<<"NO"<<endl;
    		continue;
    	}
 
    	//x>0的话，可以变奇数个白色，也可以变偶数个白色
		//但如果有2个奇数的话，无论怎么变都还是有两个奇数
    	if(f==2)cout<<"NO"<<endl;
    	else cout<<"YES"<<endl;
    }
    return 0;
}
