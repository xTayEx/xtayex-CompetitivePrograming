
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5, M = 5e6 + 5, inf = 1LL << 20;
bool isnp[N], vis[N];
vector<int> pfactor[N];

struct edge {
    int v, nxt;
};

edge e[M << 1];
int head[N], tot;

int match[N], pre[N], type[N];
int que[N], qhead, qtail;
int ft[N];

inline void addEdge(int u, int v)
{
    e[tot] = edge{ v, head[u] };
    head[u] = tot++;
}

inline int find(int x)
{
    return ft[x] == x ? x : ft[x] = find(ft[x]);
}

inline int getLca(int u, int v)
{
    static int ss[N], tim;
    tim++;
    while (ss[u] != tim) {
        if (u) {
            ss[u] = tim;
            u = find(pre[match[u]]);
        }
        swap(u, v);
    }
    return u;
}

inline void flower(int x, int y, int p)
{
    while (find(x) != p) {
        pre[x] = y;
        y = match[x];
        ft[x] = ft[y] = p;
        if (type[y] == 1) {
            que[qtail++] = y;
            type[y] = 2;
        }
        x = pre[y];
    }
}

inline bool blossom(int u, int n)
{
    qhead = qtail = 0;
    for (int i = 1; i <= n; i++) {
        type[i] = 0;
        ft[i] = i;
    }
    que[qtail++] = u;
    type[u] = 2;
    while (qhead != qtail) {
        u = que[qhead++];
        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].v;
            if (type[v] == 0) {
                type[v] = 1;
                pre[v] = u;
                if (!match[v]) {
                    while (u) {
                        u = match[pre[v]];
                        match[v] = pre[v];
                        match[match[v]] = v;
                        v = u;
                    }
                    return true;
                } else {
                    que[qtail++] = match[v];
                    type[match[v]] = 2;
                }
            } else if (type[v] == 2 && find(u) != find(v)) {
                int p = getLca(u, v);
                flower(u, v, p);
                flower(v, u, p);
            }
        }
    }
    return false;
}

void init()
{
    isnp[0] = isnp[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (isnp[i])
            continue;
        pfactor[i].emplace_back(i);
        for (int j = i + i; j < N; j += i) {
            isnp[j] = true;
            pfactor[j].emplace_back(i);
        }
    }
}

int main()
{
    //freopen("./Htable.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    init();
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << "n = " << n << "\n";
        memset(match, 0, sizeof(match));
        memset(head, -1, sizeof(head));
        tot = 0;
        for (int i = n; i >= 2; --i) {
            for (int j : pfactor[i]) {
                if (j == i)
                    continue;
                addEdge(i, i / j);
                addEdge(i / j, i);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!match[i])
                blossom(i, n);
        }
        map<int, int> mp;
        for (int i = 1; i <= n; ++i) {
            if (!match[i])
                continue;
            int u = i, v = match[i];
            if (u > v)
                swap(u, v);
            mp[u] = v;
        }
        cout << mp.size() << '\n';
        for (auto& p : mp) {
            cout << p.first << ' ' << p.second << '\n';
        }
        //cout << "=============================\n";
        cout << flush;
    }
    return 0;
}
