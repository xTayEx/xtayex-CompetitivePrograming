#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 50000 + 7;

struct Points {
    int x, y;
    Points(int x = 0, int y = 0)
        : x(x)
        , y(y)
    {
    }
};

typedef Points Vector;
Vector operator-(Points A, Points B)
{
    return Vector(A.x - B.x, A.y - B.y);
}
int n, m, maxdis;
Points p[MAXN], ch[MAXN];

int Cross(Vector A, Vector B)
{
    return A.x * B.y - A.y * B.x;
}

bool cmp(Points a, Points b)
{
    bool ret = false;
    if (a.x < b.x || (a.x == b.x && a.y < b.y)) ret = true;
    return ret;
}
void ConvexHull()
{
    sort(p, p + n, cmp);
    m = 0;
    for (int i = 0; i < n; ++i) {
        while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for (int i = n - 2; i >= 0; --i) {
        while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
        ch[m++] = p[i];
    }
    if (n > 1) m--;
    printf("m = %d\n", m);
}

int dis(Points a, Points b)
{
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}
void rotating_caliper()
{
    if (n == 3) {
        maxdis = max(dis(p[0], p[1]), dis(p[0], p[2]));
        maxdis = max(maxdis, dis(p[1], p[2]));
    } else {
        int j = 2;
        for (int i = 0; i < m; ++i) {
            while (abs(Cross(ch[i] - ch[i + 1], ch[j] - ch[i + 1])) < abs(Cross(ch[i] - ch[i + 1], ch[j + 1] - ch[i + 1]))) {
                j = (j + 1) % m;
            }
            maxdis = max(maxdis, dis(ch[i], ch[j]));
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    maxdis = -1;
    if (n == 2) {
        maxdis = dis(p[0], p[1]);
    } else {
        ConvexHull();
        rotating_caliper();
    }
    cout << maxdis;
    return 0;
}
