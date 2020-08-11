#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e6 + 5;
bool used[N];

bool solve(int p, int now, int tot)
{
    if (tot == p - 1)
        return true;
    bool ret = false;
    for (int i = 2; i <= 3; ++i) {
        if (used[now * i % p])
            continue;

        used[now * i % p] = true;
        ret |= solve(p, now * i % p, tot + 1);
        used[now * i % p] = false;

        if (ret == true)
            return true;
    }
    return false;
}

int main()
{
    int p = 5;
    while (cin >> p) {
        memset(used, 0, sizeof(used));
        if (solve(p, 1, 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
