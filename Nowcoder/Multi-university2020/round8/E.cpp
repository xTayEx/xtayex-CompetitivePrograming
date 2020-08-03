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
int ans;
vector<int> vec;
void show()
{
    for (auto it : vec) {
        printf("%d ", it);
    }
    puts("");
}
void getf(int target, int add, int now)
{
    now += add;
    vec.push_back(add);
    if (now == target) {
        if (vec.back() - vec.front() == 2) {
            show();
            ans++;
        }
        return;
    }
    if (now > target) {
        return;
    }
    getf(target, add, now);
    vec.pop_back();
    getf(target, add + 1, now);
    vec.pop_back();
}
int main()
{
    int tar;
    while (scanf("%d", &tar) != EOF) {
        ans = 0;
        for (int i = 1; i <= tar; i++) {
            vec.clear();
            getf(tar, i, 0);
        }
        printf("%d\n", ans);
    }
    return 0;
}
