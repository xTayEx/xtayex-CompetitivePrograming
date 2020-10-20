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
#include <unistd.h>
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
vector<string> lines;
vector<string> output;
int paracnt;
int itemcnt;
string trim(string s)
{
    int st = 0;
    while (s[st] == ' ' || s[st] == '\t') st++;
    int ed = s.size() - 1;
    while (s[ed] == ' ' || s[ed] == '\t') ed--;
    string ret = "";
    for (int i = st; i <= ed; i++) {
        ret.push_back(s[i]);
    }
    return ret;
}
string trim_head(string s)
{
    int st = 0;
    while (s[st] == ' ' || s[st] == '\t') st++;
    string ret = "";
    int sz = s.size();
    for (int i = st; i < sz; i++) {
        ret.push_back(s[i]);
    }
    return ret;
}
string trim_tail(string s)
{
    int ed = s.size() - 1;
    while (s[ed] == ' ' || s[ed] == '\t') ed--;
    string ret = "";
    for (int i = 0; i <= ed; i++) {
        ret.push_back(s[i]);
    }
    return ret;
}
bool is_empty_line(string s)
{
    string res = trim(s);
    return res.empty();
}
enum TYPE {
    ITEMHEAD,
    ITEMCHILD,
    PARA,
    EMPTY,
    UNDEFINED
};
int check_basic_type(string s)
{
    if (s[0] == '*' && s[1] == ' ')
        return ITEMHEAD;
    else if (!is_empty_line(s))
        return PARA;
    else if (is_empty_line(s))
        return EMPTY;
    else if (!is_empty_line(s) && s.size() >= 2 && s[0] == ' ' && s[1] == ' ')
        return ITEMCHILD;
    else
        return UNDEFINED;
}
int check_sub_type(string s)
{
    s = trim_head(s);
    return check_basic_type(s);
}
void show()
{
    int sz = output.size();
    for (int i = 1; i < sz; i++) {
        cout << output[i] << "\n";
        //debug(output[i].size());
    }
}
void write_para(string para, int wid, int preoffset)
{
    //debug(para);
    string s = "";
    para = trim(para);
    int len = para.size();
    int p = 0;
    while (p + wid - preoffset < len) {
        while (para[p] == ' ' || para[p] == '\t') p++;
        s = para.substr(p, min((int)para.size(), wid));
        for (int i = 0; i < preoffset; i++) {
            s = " " + s;
        }
        output.push_back(s);
        p += (wid - preoffset);
    }
    if (p < len) {
        s = trim(para.substr(p));
        for (int i = 0; i < preoffset; i++) {
            s = " " + s;
        }
        output.push_back(s);
    }
}
void write_list(string itemlist, int wid)
{
    itemlist = itemlist.substr(2);
    int len = itemlist.size();
    string s = "";
    int p = 0;
    int linecnt = 0;
    while (p + wid - 3 < len) {
        while (itemlist[p] == ' ' || itemlist[p] == '\t') p++;
        s = itemlist.substr(p, min((int)itemlist.size(), wid - 3));
        if (linecnt == 0) {
            s = " • " + s;
            //debug(s);
        } else {
            s = "   " + s;
        }
        output.push_back(s);
        linecnt++;
        p += (wid - 3);
    }
    if (p < len) {
        s = trim(itemlist.substr(p));
        if (linecnt == 0)
            s = " • " + s;
        else
            s = "   " + s;
        output.push_back(s);
    }
}
void write_list_head(string list_head, int wid)
{
    debug(list_head);
    list_head = list_head.substr(2);
    int len = list_head.size();
    string s = "";
    int p = 0;
    int linecnt = 0;
    while (p + wid - 3 < len) {
        while (list_head[p] == ' ' || list_head[p] == '\t') p++;
        s = list_head.substr(p, min((int)list_head.size(), wid - 3));
        if (linecnt == 0) {
            s = " • " + s;
        } else {
            s = "   " + s;
        }
        output.push_back(s);
        linecnt++;
        p += (wid - 3);
    }
    if (p < len) {
        s = trim(list_head.substr(p));
        if (linecnt == 0) {
            s = " • " + s;
        } else {
            s = "   " + s;
        }
        output.push_back(s);
    }
}
struct edge {
    int nxt;
    int to;
};
int head[maxn];
edge es[maxn];
int edgecnt;
inline void list_tree_init()
{
    mst(head, -1);
    edgecnt = 0;
}
inline void addedge(int u, int v)
{
    es[edgecnt].nxt = head[u];
    es[edgecnt].to = v;
    head[u] = edgecnt++;
}
void build_list_tree(int rt)
{
}
int main()
{
    freopen("markdowntest_itemlist.in", "r", stdin);
    //freopen("markdowntest.out","w",stdout);
    paracnt = itemcnt = 0;
    int w;
    cin >> w;
    string line;
    int line_cnt = 0;
    getline(cin, line);
    while (getline(cin, line)) {
        if (cin.eof()) break;
        lines.push_back(line);
        line_cnt++;
    }
    int cur = 0;
    while (cur < line_cnt) {
        int type = check_basic_type(lines[cur]);
        if (type == PARA) {
            paracnt++;
            int emptyline = cur;
            while (emptyline < line_cnt && !is_empty_line(lines[emptyline]))
                emptyline++;
            emptyline += (emptyline == line_cnt - 1);
            string para = "";
            for (int i = cur; i < emptyline; i++) {
                if (i != cur)
                    para += " " + trim(lines[i]);
                else
                    para += trim(lines[i]);
            }
            output.push_back("");
            write_para(para, w, 0);
            cur = emptyline;
            while (cur < line_cnt && is_empty_line(lines[cur]))
                cur++;
        } else if (type == EMPTY) {

        } else if (type == ITEMHEAD) {
            int emptyline = cur + 1;
            while (emptyline < line_cnt
                && !is_empty_line(lines[emptyline]))
                emptyline++;
            emptyline += (emptyline == line_cnt - 1);
            string itemlist = "";
            output.push_back("");
            write_list_head(lines[cur], w);
            for(int i = cur + 1; i < emptyline; i++) {
                int subtype = check_sub_type(lines[i]);
                if(subtype == PARA) {
                    
                } else if (subtype == ITEMHEAD) {

                }
            }
            cur = emptyline;
            while (cur < line_cnt && is_empty_line(lines[cur]))
                cur++;
        } else if (type == UNDEFINED) {
        }
    }
    show();
    return 0;
}
