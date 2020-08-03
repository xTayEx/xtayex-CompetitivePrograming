#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define mst(a, b) memset((a), (b), sizeof(a))
#define debug printf("debug\n")
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct node {
    int val[4];
    int nodeval;
};
node ns[256 + 5];
char s[105];
unordered_map<string, int> mp1, mp2, mp3, mp4;
unordered_map<int, int> Mp;
vector<int> vec;
inline void init()
{
    mp1["one"] = 1, mp1["two"] = 2, mp1["three"] = 3, mp1["*"] = 4;
    mp2["diamond"] = 1, mp2["squiggle"] = 2, mp2["oval"] = 3, mp2["*"] = 4;
    mp3["solid"] = 1, mp3["striped"] = 2, mp3["open"] = 3, mp3["*"] = 4;
    mp4["red"] = 1, mp4["green"] = 2, mp4["purple"] = 3, mp4["*"] = 4;
}
int trans(int v1, int v2, int v3, int v4)
{
    int ret = v1 * 1000 + v2 * 100 + v3 * 10 + v4;
    return ret;
}
void dfs(int cur, int now, node& n1, node& n2)
{
    if (cur >= 4) {
        vec.push_back(now);
        return;
    }
    if (n1.val[cur] == n2.val[cur]) {
        dfs(cur + 1, now * 10 + n1.val[cur], n1, n2);
        dfs(cur + 1, now * 10 + 5, n1, n2);
    } else {
        dfs(cur + 1, now * 10 + (6 - n1.val[cur] - n2.val[cur]), n1, n2);
        dfs(cur + 1, now * 10 + 5, n1, n2);
    }
}
int main()
{
    init();
    int T;
    scanf("%d", &T);
    int kase = 0;
    while (T--) {
        printf("Case #%d: ", ++kase);
        int N;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%s", s + 1);
            int len = strlen(s + 1);
            int lef = 1;
            int rig = 1;
            string tmp;
            int Val = 0;
            int lefcnt = 1;
            int nsidx = 1;
            Mp.clear();
            while (lef <= rig && lef <= len && rig <= len) {
                while (s[rig] != ']')
                    rig++;
                tmp.clear();
                for (int i = lef; i <= rig; i++) {
                    tmp.push_back(s[i]);
                }
                if (lefcnt == 1) {
                    ns[nsidx].val[0] = mp1[tmp];
                    Val = Val * 10 + mp1[tmp];
                } else if (lefcnt == 2) {
                    ns[nsidx].val[1] = mp2[tmp];
                    Val = Val * 10 + mp2[tmp];
                } else if (lefcnt == 3) {
                    ns[nsidx].val[2] = mp3[tmp];
                    Val = Val * 10 + mp3[tmp];
                } else if (lefcnt == 4) {
                    ns[nsidx++].val[3] = mp4[tmp];
                    Val = Val * 10 + mp4[tmp];
                    ns[nsidx - 1].nodeval = Val;
                    Mp[Val] = i;
                    Val = 0;
                }
                lef = rig + 1;
                rig = lef;
                lefcnt++;
            }
        }
        bool flag = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                int todo = 0;
                node& n1 = ns[i];
                node& n2 = ns[j];
                vec.clear();
                dfs(0, 0, n1, n2);
                int sz = vec.size();
                for (int k = 0; k < sz; k++) {
                    if (Mp[vec[k]]) {
                        printf("%d %d %d\n", i, j, Mp[vec[k]]);
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
        if (!flag)
            puts("-1");
    }
    return 0;
}
