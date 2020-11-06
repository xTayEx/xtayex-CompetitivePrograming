
#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<string, int> mp;
int main()
{
    mp["London"] = 0;
    mp["Moscow"] = 3;
    mp["Washington"] = -5;
    mp["Beijing"] = 8;
    int t;
    cin >> t;
    int T = 0;
    while (t--) {
        int h, m;
        scanf("%d:%d", &h, &m);
        string p;
        cin >> p;
        if (p == "PM") {
            h += 12;
        }
        string a, b;
        cin >> a >> b;
        int f = mp[a], s = mp[b];
        h -= (f - s);
        cout << "Case " << ++T << ": ";
        if (h < 1) {
            h += 24;
            if (h != 24)
                cout << "Yesterday ";
            else
                cout << "Today ";
        } else if (h >= 24) {
            if (h != 24)
                h -= 24;
            cout << "Tomorrow ";
        } else {
            cout << "Today ";
        }
        cout << "h: " << h << "\n";
        int pm = 0;
        if (h >= 24) {
            h -= 24;
            pm = 0;
        } else if (h >= 12) {
            if (h != 12)
                h -= 12;
            pm = 1;
        }
        if (h == 0) {
            h = 12;
            pm = 1;
        }
        printf("%d:%02d ", h, m);
        if (pm) {
            cout << "PM\n";
        } else
            cout << "AM\n";
    }
}
