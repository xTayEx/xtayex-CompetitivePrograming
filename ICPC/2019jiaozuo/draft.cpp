#include <bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    cin>>t;
    while(t--){
        double a,b,r,d;
        cin>>a>>b>>r>>d;
        d = d/180*acos(-1);     // 转化为弧度
        double red = sqrt((a+r)*(a+r)+b*b);
        double x = acos((a+r)/red);
        if(x <= d){
            printf("%.12f\n",red-r);
        }else{
            double y = x-d;
            double yellow = red*cos(y);
            printf("%.12f\n",yellow-r);
        }
    }
}
