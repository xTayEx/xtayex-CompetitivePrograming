#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, INF = numeric_limits<int>::max();

int f[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, minf = INF, cntf = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int a, d;
            scanf("%d%d", &a, &d);
            f[i] = (100 + a - 1) / a * d;
            minf = min(f[i], minf);
        }

        for (int i = 0; i < n; ++i)
            cntf += (f[i] == minf);

        printf("%.6f\n", 1 - cntf / double(n) * 0.5);
    }
    return 0;
}
