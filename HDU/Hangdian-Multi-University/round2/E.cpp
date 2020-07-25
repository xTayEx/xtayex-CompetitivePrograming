#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <utility>
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
const int maxn=1e4+5;
const int maxm=1e5+5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct edge{
    int to,nxt,cap,flow,cost;
}es[maxm];
int head[maxn];
int tol;
int pre[maxn],dis[maxn];
bool vis[maxn];
int N;
inline void init(int n)
{
    N=n;
    tol=0;
    mst(head,-1);
}
void addedge(int u,int v,int cap,int cost)
{
    es[tol].to=v;
    es[tol].cap=cap;
    es[tol].cost=cost;
    es[tol].flow=0;
    es[tol].nxt=head[u];
    head[u]=tol++;

    es[tol].to=u;
    es[tol].cap=0;
    es[tol].cost=-cost;
    es[tol].flow=0;
    es[tol].nxt=head[v];
    head[v]=tol++;
}
bool spfa(int s,int t)
{
    queue<int> que;
    for(int i=0;i<N;i++){
        dis[i]=INF;
        vis[i]=false;
        pre[i]=-1;
    }
    dis[s]=0;
    vis[s]=true;
    que.push(s);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        vis[u]=false;
        for(int i=head[u];i!=-1;i=es[i].nxt){
            int v=es[i].to;
            if(es[i].cap>es[i].flow&&dis[v]>dis[u]+es[i].cost){
                dis[v]=dis[u]+es[i].cost;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=true;
                    que.push(v);
                }
            }
        }
    }
    return pre[t]!=-1;
}
int mcmf(int s,int t,int& cost)
{
    int flow=0;
    cost=0;
    while(spfa(s,t)){
        int Min=INF;
        for(int i=pre[t];i!=-1;i=pre[es[i^1].to]){
            if(Min>es[i].cap-es[i].flow){
                Min=es[i].cap-es[i].flow;
            }
        }
        for(int i=pre[t];i!=-1;i=pre[es[i^1].to]){
            es[i].flow+=Min;
            es[i^1].flow-=Min;
            cost+=es[i].cost*Min;
        }
        flow+=Min;
    }
    return flow;
}
struct worker{
    ll a,b,c;
};
worker ns[52];
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        int n,m;scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%lld %lld %lld",&ns[i].a,&ns[i].b,&ns[i].c); 
        }
    }
}
