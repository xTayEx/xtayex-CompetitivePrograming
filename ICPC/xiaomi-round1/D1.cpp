#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 45000
/*
去掉一个割点后，询问可以分得的联通图的个数模板
*/
struct node {
    int u, v, next;
} edge[N * 10];
/*cut数组记录去掉某个节点后可以增加的联通分支的个数,num数组记录以i为根节点的联通图的元素的个数*/
int head[N], n, yong, cou, Index, dfn[N], low[N], cut[N], num[N];
void init()
{
    yong = 0;
    Index = 0;
    cou = 0;
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(num, 0, sizeof(num));
    memset(cut, 0, sizeof(cut));
}
int Min(int a, int b)
{
    return a > b ? b : a;
}
void addedge(int u, int v)
{
    edge[yong].u = u;
    edge[yong].v = v;
    edge[yong].next = head[u];
    head[u] = yong++;
}
void tarjan(int u, int pre)
{
    int i;
    dfn[u] = low[u] = ++Index;
    cou++;
    if (pre < 0) //根节点去掉后无影响，或则单个孤立节点的计算标记
        cut[u]--;
    for (i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v != pre) {
            if (!dfn[v]) {
                tarjan(v, u);
                low[u] = Min(low[u], low[v]);
                if (low[v] >= dfn[u]) //割点去掉后可增加联通分量
                    cut[u]++;
            } else
                low[u] = Min(low[u], dfn[v]);
        }
    }
}
int main()
{
    int m, a, b, i, flag, ans, sum;
    scanf("%d%d", &n, &m);
    init();
    while (m--) {
        scanf("%d%d", &a, &b);
        addedge(a, b);
        addedge(b, a);
    }
    sum = 0;
    for (i = 1; i <= n; i++) {
        if (!dfn[i]) {
            cou = 0;
            sum++; //记录有多少个联通块
            tarjan(i, -1);
            num[i] = cou; //记录以i为根节点的联通分量的元素的个数
        }
    }
    flag = -1;
    ans = 0;
    for (i = 1; i <= n; i++) {
        cout << sum + cut[i] << " ";
    }
    cout << endl;
    return 0;
}
