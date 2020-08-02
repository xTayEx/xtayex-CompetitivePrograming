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
const int maxn = 1e5 + 5;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char s[maxn];
deque<int> que;
stack<int> stklef;
//stack<int> stkrig;
inline void init()
{
    while (!que.empty())
        que.pop_back();
    while (!stklef.empty())
        stklef.pop();
    //while(!stkrig.empty()) stkrig.pop();
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        bool flag = 1;
        for (int i = 1; i <= len; i++) {
            if (s[i] == '(') {
                stklef.push(i);
            } else if (s[i] == ')') {
                if (!stklef.empty()) {
                    stklef.pop();
                } else {
                    if (!que.empty()) {
                        int Front = que.front();
                        que.pop_front();
                        s[Front] = '(';
                    } else {
                        flag = 0;
                        break;
                    }
                }
            } else if (s[i] == '*') {
                que.push_back(i);
            }
        }
        while (!stklef.empty()) {
            if (!que.empty() && que.back() > stklef.top()) {
                //printf("que.back() = %d, stklef.top() = %d\n",que.back(),stklef.top());
                int ba = que.back();
                s[ba] = ')';
                que.pop_back();
                stklef.pop();
            } else {
                flag = 0;
                break;
            }
        }
        if (flag) {
            for (int i = 1; i <= len; i++) {
                if (s[i] != '*') {
                    printf("%c", s[i]);
                }
            }
            printf("\n");
        } else {
            puts("No solution!");
        }
    }
    return 0;
}
