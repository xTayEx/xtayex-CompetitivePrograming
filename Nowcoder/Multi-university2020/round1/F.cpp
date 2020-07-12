#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solve(const string& s) {
    int n = s.length();
    vector<int> nxt(n + 5);
    int j = 0, k = -1;
    nxt[0] = -1;
    while (j <= n) {
        if (k == -1 || s[j] == s[k])
            nxt[++j] = ++k;
        else
            k = nxt[k];
    }
    int len = n - nxt[n];
    if (s.length() % len != 0) return s.length();
    return len;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s, t;
    while(cin >> s >> t) {
        int a = solve(s);
        int b = solve(t);

        if (a == b && s.substr(0, a) == t.substr(0, b)) {
            cout << "=" << endl;
            continue;
        }

        s += s + s;
        t += t + t;

        if (s < t) {
            cout << "<" << endl;
        } else {
            cout << ">" << endl;
        }
       
    }
    return 0;
}
