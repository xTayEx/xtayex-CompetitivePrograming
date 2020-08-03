#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

unordered_map<int, int> lmp;
unordered_set<int> s;
unordered_map<int, vector<int>> mp;
vector<int> p;

int main()
{
    int t, n;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        s.clear(), lmp.clear(), mp.clear(), p.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x < y)
                swap(x, y);
            ++lmp[x];
            mp[x].emplace_back(y);
            p.emplace_back(x);
        }

        sort(p.begin(), p.end(), greater<int>());

        for (int i = 0; i < p.size(); ++i) {
            int x = p[i];
            auto& vec = mp[p[i]];

            s.emplace(x);
            int idx = 0, maxval = -1;
            for (int j = 0; j < vec.size(); ++j) {
                int temp = lmp[vec[j]];
                if (maxval == -1 || temp > maxval)
                    idx = j, maxval = temp;
            }

            for (int j = 0; j < vec.size(); ++j)
                if (j != idx)
                    s.emplace(vec[j]);

            lmp[x] -= vec.size();
        }
        int ans = s.size();
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
