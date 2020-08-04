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
};
node ns[256 + 5];
unordered_map<string, int> mp1, mp2, mp3, mp4;
inline void init()
{
    mp1["one"] = 1, mp1["two"] = 2, mp1["three"] = 3, mp1["*"] = 4;
    mp2["diamond"] = 1, mp2["squiggle"] = 2, mp2["oval"] = 3, mp2["*"] = 4;
    mp3["solid"] = 1, mp3["striped"] = 2, mp3["open"] = 3, mp3["*"] = 4;
    mp4["red"] = 1, mp4["green"] = 2, mp4["purple"] = 3, mp4["*"] = 4;
}
char s1[15], s2[15], s3[15], s4[15];
void solve(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                const node& n1 = ns[i];
                const node& n2 = ns[j];
                const node& n3 = ns[k];
                int cnt = 0;
                for (int idx = 0; idx < 4; idx++) {
                    if (n1.val[idx] != 4 && n2.val[idx] != 4) {
                        if (n1.val[idx] == n2.val[idx]) {
                            if (n2.val[idx] == n3.val[idx] || n3.val[idx] == 4) {
                                cnt++;
                            }
                        } else {
                            if (n3.val[idx] == 6 - n1.val[idx] - n2.val[idx] || n3.val[idx] == 4) {
                                cnt++;
                            }
                        }
                    } else if ((n1.val[idx] != 4 && n2.val[idx] == 4) || (n1.val[idx] == 4 && n2.val[idx] != 4)) {
                        cnt++;
                    } else {
                        cnt++;
                    }
                }
                if (cnt == 4) {
                    printf("%d %d %d\n", i, j, k);
                    return;
                }
            }
        }
    }
    puts("-1");
}
int main()
{
    init();
    int T;
    scanf("%d", &T);
    int kase = 0;
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            getchar();
            scanf("[%99[^]]][%99[^]]][%99[^]]][%99[^]]]", s1 + 1, s2 + 1, s3 + 1, s4 + 1);
            ns[i].val[0] = mp1[string(s1 + 1)];
            ns[i].val[1] = mp2[string(s2 + 1)];
            ns[i].val[2] = mp3[string(s3 + 1)];
            ns[i].val[3] = mp4[string(s4 + 1)];
        }
        printf("Case #%d: ", ++kase);
        solve(N);
    }
    return 0;
}
