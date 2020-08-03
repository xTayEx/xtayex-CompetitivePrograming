
#include <algorithm>
#include <cctype>
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
const int maxn = 1505;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
string str[maxn];
char ch[] = { ' ', 'S', 'E', 'T' };
unordered_map<string, bool> mp;
unordered_map<char, int> char_mp;
inline void init()
{
    char_mp['S'] = 1;
    char_mp['E'] = 2;
    char_mp['T'] = 3;
}
int main()
{
    init();
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        mp[str[i]] = 1;
    }
    string tmp = "";
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tmp.clear();
            string& s1 = str[i];
            string& s2 = str[j];
            for (int kk = 0; kk < k; kk++) {
                if (s1[kk] == s2[kk]) {
                    tmp.push_back(s1[kk]);
                } else {
                    tmp.push_back(ch[6 - char_mp[s1[kk]] - char_mp[s2[kk]]]);
                }
            }
            if (mp[tmp])
                ans++;
        }
    }
    printf("%d\n", ans / 3);
    return 0;
}
