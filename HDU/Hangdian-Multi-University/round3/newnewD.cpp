#include <bits/stdc++.h>
using namespace std;

multiset<int> st;

int main()
{
    int t, n, p;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &p);
        st.clear();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            if (x % p)
                st.emplace(x % p);
            else
                ans++;
        }

        while (!st.empty()) {
            int u = *st.rbegin();
            if (st.size() == 1) {
                if (u % p == 0)
                    ans++;
                st.erase(st.begin());
            } else {
                st.erase(prev(st.end()));
                auto iter = st.find(p - u);
                if (iter == st.end()) {
                    int v = *st.begin();
                    st.emplace((u + v) % p);
                } else {
                    ans++;
                    st.erase(iter);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
