
#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
 
const int N = 2e6 + 7;
 
unordered_map<int, int>vis;
 
int le[N], a[N];
 
int main() {
    freopen("./Kgen.in", "r", stdin);
    int t; scanf("%d", &t);
    while (t--) {
 
        vis.clear();
        int n, k; scanf("%d %d", &n, &k);
        int f = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] > k) {
                f = 1;
            }
        }
        if (f) {
            puts("NO");
        } else if (k >= n) {
            int l = 1;
            while (l <= n && vis[a[l]] == 0) vis[a[l]] = 1, l++;
            vis.clear();
            int r = n;
            while(r <= n && vis[a[r]] == 0) vis[a[r]] = 1, r--;
            if (l > r) {
                puts("YES");
            } else {
                puts("NO");
            }
        } else {
            int l = 1;
            for (int i = 1; i <= n; i++) {
                while (l <= n && vis[a[l]] == 0) {
                    vis[a[l]] = 1;
                    l++;
                }
                le[i] = l;
                vis[a[i]] = 0;
            }
            int flag = 0;
            for (int i = 1; i < le[1]; i++) {
                int ok = 0;
                for (int j = i + 1; j <= n; j += k) {
                    if (le[j] > n) {
                        break;
                    }
                    if (le[j] - j != k) {
                        ok = 1;
                        break;
                    }
                }
                if (ok == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                puts("YES");
            } else {
                puts("NO");
            }
             
        }
    }
}
