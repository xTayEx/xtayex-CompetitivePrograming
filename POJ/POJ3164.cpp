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
//#include <unordered_map>
#define mst(a,b) memset((a),(b),sizeof(a))
#define debug printf("debug\n")
#define INF 0x3f3f3f3f
#define lson lef,mid,rt<<1
#define rson mid+1,rig,rt<<1|1
const int maxn=1e2+5;
const int maxm=2e4+5;
const double dinf=1e18;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct edge{
    int u;
    int v;
    double dis;
    edge(int u,int v,double dis)
        :u(u)
        ,v(v)
        ,dis(dis)
    {}
    edge(){}
};
edge es[maxm];
struct node{
    double x;
    double y;
    node(double x,double y)
        :x(x)
        ,y(y)
    {}
    node(){}
};
node ns[maxn];
int pre[maxn];
int id[maxn];
int vis[maxn];
double inedge[maxn];
double sqr(double x)
{
    return x*x;
}
double dist(const node& na,const node& nb)
{
    return sqrt(sqr(nb.x-na.x)+sqr(nb.y-na.y));
}
void zhuliu(int root,int n,int m,edge E[])
{
    double res=0;
    int v;
    while(1){
        for(int i=0;i<n;i++){
            inedge[i]=dinf;
        }
        for(int i=0;i<m;i++){
            if(es[i].u!=es[i].v&&es[i].dis<inedge[es[i].v]){
                pre[es[i].v]=es[i].u;
                inedge[es[i].v]=es[i].dis;
            }
        }
        for(int i=0;i<n;i++){
            if(i!=root&&inedge[i]==dinf){ // 某个点不可达
                //printf("i = %d\n",i);
                puts("poor snoopy");
                return ;
            }
        }
        mst(id,-1);mst(vis,-1);
        int tn=0;
        inedge[root]=0;
        for(int i=0;i<n;i++){
            res+=inedge[i];
            v=i;
            while(vis[v]!=i&&id[v]==-1&&v!=root){
                vis[v]=i;
                v=pre[v];
            }
            if(v!=root&&id[v]==-1){
                for(int u=pre[v];u!=v;u=pre[u]){
                    id[u]=tn;
                }
                id[v]=tn++;
            }
        }
        if(tn==0) break;
        for(int i=0;i<n;i++){
            if(id[i]==-1){
                id[i]=tn++;
            }
        }
        for(int i=0;i<m;i++){
            v=es[i].v;
            es[i].u=id[es[i].u];
            es[i].v=id[es[i].v];
            if(es[i].u!=es[i].v){
                es[i].dis-=inedge[v];
            }
        }
        n=tn;
        root=id[root];
    }
    printf("%.2f\n",res);
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        double x,y;
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&x,&y);
            ns[i]=node(x,y);
        }
        int u,v;double Dis;
        for(int i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            u--;v--;
            if(u==v) Dis=dinf;
            else Dis=dist(ns[u],ns[v]);
            es[i]=edge(u,v,Dis);
        }
        zhuliu(0, n, m, es);
    }
    return 0;
}
