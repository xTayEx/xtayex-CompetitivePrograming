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
#define debug(x) cerr << "\033[01;31m" << #x << " = " << x << "\033[0m" \
                      << "\n"
#define INF 0x3f3f3f3f
#define lson lef, mid, rt << 1
#define rson mid + 1, rig, rt << 1 | 1
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
vector<int> vi, rs;
set<int> st;
unordered_map<int, int> pows;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
struct fraction {
    int up;
    int down;
    fraction operator+(const fraction& argu) const
    {
        int Lcm = lcm(up, down);
        int up1 = Lcm / down;
        int up2 = Lcm / argu.down;
        fraction ret;
        ret.up = up1 + up2;
        ret.down = Lcm;
        return ret;
    }
};
void init()
{
    pows.clear();
    for (int i = 1; i <= 100; i++) pows[i * i] = i;
}
void frac(int val)
{
    vi.clear();
    vi.push_back(1);
    for (int i = 2; i * i <= val; i++) {
        while (val % i == 0) {
            vi.push_back(i);
            val /= i;
        }
    }
    if (val > 1) vi.push_back(val);
}
int calc(int i)
{
    if (pows.count(i))
        return INF;
    else
        return i;
}
void getTotal()
{
    int siz = rs.size();
    double down = 0;
    for (int i = 0; i < siz; i++) {
        down += 1.0 / rs[i];
    }
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            rs.clear();
            frac(i);
            int siz = vi.size();
            for (int j = 0; j < siz; j++) {
                int r = calc(vi[j]);
                rs.push_back(r);
            }
        }
    }
    return 0;
}
