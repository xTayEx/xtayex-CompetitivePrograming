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
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
unordered_map<string, int> wins, score, place[51];
unordered_map<string, bool> vis;
int sc[] = { 25, 18, 15, 12, 10, 8, 6, 4, 2, 1 };
vector<string> vec;
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    vec.clear(), wins.clear(), score.clear();
    vis.clear();
    while (T--) {
        int n;
        cin >> n;
        string name;
        for (int i = 0; i < n; i++) {
            cin >> name;
            if (!vis[name]) vis[name] = 1, vec.push_back(name);
            score[name] += (i <= 9 ? sc[i] : 0);
            if (i == 0)
                wins[name]++;
            else
                place[i][name]++;
        }
    }
    sort(vec.begin(), vec.end(), [&](string& a, string& b) {
        if (score[a] != score[b])
            return score[a] > score[b];
        else if (wins[a] != wins[b])
            return wins[a] > wins[b];
        int pos = 0;
        for (int i = 1; i < 51; i++) {
            if (place[i][a] != place[i][b]) {
                pos = i;
                break;
            }
        }
        return place[pos][a] > place[pos][b];
    });
    cout << vec[0] << "\n";
    sort(vec.begin(), vec.end(), [&](string& a, string& b) {
        if (wins[a] != wins[b])
            return wins[a] > wins[b];
        else if (score[a] != score[b])
            return score[a] > score[b];
        int pos = 0;
        for (int i = 1; i < 51; i++) {
            if (place[i][a] != place[i][b]) {
                pos = i;
                break;
            }
        }
        return place[pos][a] > place[pos][b];
    });
    cout << vec[0] << "\n";
    return 0;
}
