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
const double eps=1e-3;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int sgn(double x)
{
    double Eps=1e-8;
    if(fabs(x)<Eps){
        return 0;
    }
    if(x<0) return -1;
    else return 1;
}
struct point{
    double x;
    double y;
    point(){}
    point(double _x,double _y){
        x=_x;y=_y;
    }
    point operator-(const point& b)const{
        return point(x-b.x,y-b.y);
    }
    double operator^(const point& b)const{
        return x*b.y-y*b.x;
    }
};
struct line{
    point s,e;
    line(){}
    line(point _s,point _e){
        s=_s;e=_e;
    }
    int relation(point p){
        int c=sgn((p-s)^(e-s));
        if(c<0) return 1;
        else if(c>0) return 2;
        else return 3;
    }
};
point ps[22];
double sqr(double x)
{
    return x*x;
}
double dist(const point& pa,const point& pb)
{
    return sqrt(sqr(pa.x-pb.x)+sqr(pa.y-pb.y));
}
bool check(const point& pa,const point& pb,const point& pc,const point& pd)
{
    double dis1=dist(pa,pb);
    double dis2=dist(pc,pd);
    //printf("dis1 = %lf, dis2 = %lf, %lf, %lf\n",dis1,dis2,fabs(dis1-3.0),fabs(dis2-6.0));
    if((fabs(dis1-6.00)<eps&&fabs(dis2-3.00)<eps)||(fabs(dis1-3.00)<eps&&fabs(dis2-6.00)<eps)) return 1;
    return 0;
}
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        double X,Y;
        for(int i=0;i<20;i++){
            scanf("%lf %lf",&X,&Y);
            ps[i].x=X;ps[i].y=Y;
        }
        int pos;
        int idx1,idx2,idx3,idx4;
        for(int i=0;i<20;i++){
            idx1=i;idx2=(i+1)%20;
            idx3=(i+2)%20;idx4=(i+3)%20;
            if(check(ps[idx1],ps[idx2],ps[idx3],ps[idx4])){
                pos=i;
                break;
            }
        }  
        //printf("pos = %d\n",pos);
        line L(ps[pos],ps[(pos+1)%20]);
        int lef=0;
        int rig=0;
        for(int i=(pos+2)%20;i!=pos;i=(i+1)%20){
            int rela=L.relation(ps[i]);
            if(rela==1) lef++;
            else if(rela==2) rig++;
        }
        if(lef<rig) puts("right");
        else puts("left");
    }
    return 0;
}
