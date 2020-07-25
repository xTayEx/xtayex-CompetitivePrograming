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
const int maxn = 8e5 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a[maxn], b[maxn];
int p[maxn];
int ni[maxn], nif[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        b[i] = a[(i + n + p[1]) % n];
    }
    memset(ni, 0, sizeof(ni));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (b[j] < b[i]) {
                ni[b[i]]++;
                nif[b[j]]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int maxv = 0, pos = -1, f = 0;
        for (int j = 1; j <= n; j++) {
            if (maxv < ni[j]) {
                maxv = ni[j];
                pos = j;
                f = 0;
            }
            if (maxv < nif[j]) {
                maxv = nif[j];
                pos = j;
                f = 1;
            }
        }
        if (pos == -1)
            break;
        ans++;
        int p;
        for (int j = 0; j < n; j++) {
            if (b[j] == pos) {
                p = j;
                break;
            }
        }

        if (f == 0) {
            int tmp = p;
            while (ni[pos]) {
                if (b[tmp] > b[tmp + 1]) {
                    ni[pos]--;
                    nif[b[tmp + 1]]--;
                }
                swap(b[tmp], b[tmp + 1]);
                tmp++;
            }
        } else {
            int tmp = p;
            while (nif[pos]) {
                if (b[tmp] < b[tmp - 1]) {
                    ni[b[tmp - 1]]--;
                    nif[pos]--;
                }
                swap(b[tmp], b[tmp - 1]);
                tmp--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*
8
8 4 5 7 3 6 2 1*/
