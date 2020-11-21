#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

typedef long long LL;

typedef unsigned long long ull;

const int inf = 0x3f3f3f3f;

const int N = 1e5 + 100;

struct Node {
    LL pos, t;
    bool flag; //开始点:0,结束点:1
    Node(LL pos, LL t, bool flag)
        : pos(pos)
        , t(t)
        , flag(flag)
    {
    }
    bool operator<(const Node& t) const
    {
        if (pos != t.pos)
            return pos < t.pos;
        return flag < t.flag;
    }
};

vector<Node> node;

multiset<LL> st;

int main()
{
#ifndef ONLINE_JUDGE
//  freopen("data.in.txt","r",stdin);
//  freopen("data.out.txt","w",stdout);
#endif
    //  ios::sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        LL l, r, t;
        scanf("%lld%lld%lld", &l, &r, &t);
        node.push_back(Node(l + t, t, 0));
        node.push_back(Node(r, t, 1));
    }
    sort(node.begin(), node.end()); //按照l[i]+t[i]升序排序，满足情况1
    LL ans = 0, pre = 0;
    for (Node t : node) {
        if (!st.empty()) //如果当前有房子开放
        {
            LL num = (t.pos - pre) / (*st.begin()); //贪心计算贡献
            ans += num;
            pre += num * (*st.begin());
        }
        if (t.flag) //结束点
            st.erase(st.find(t.t));
        else //开始点
        {
            if (pre + t.t <= t.pos) //到达开始点l[i]+t[i]时就可以铸一把剑了
            {
                ans++;
                pre = t.pos;
            }
            st.insert(t.t);
        }
    }
    printf("%lld\n", ans);

    return 0;
}
