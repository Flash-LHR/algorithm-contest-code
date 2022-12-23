#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T& x)
{
    x = 0; int f = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
    x *= f;
}

template <typename T>
void print(T x)
{
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

template <typename T>
void print(T x, char ch)
{
    print(x), putchar(ch);
}

typedef double db;
typedef long long ll;
typedef unsigned long long ull;

const int M = (int)1e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n, m;
string s[2][M + 5];
int id[M + 5];
unordered_map<ull, int> mp[2];
unordered_set<ull> st[2];
vector<ull> h, pw;
bool ans[2][M + 5];

void build(int p, int id)
{
    int len = (int)s[p][id].size();
    h.resize(len + 1), pw.resize(len + 1);
    pw[0] = 1, h[0] = 0;
    for(int i = 1; i <= len; ++i)
    {
        pw[i] = pw[i - 1] * 131;
        h[i] = h[i - 1] * 131 + s[p][id][i - 1] - 'a' + 1;
    }
}

ull calc(int l, int r)
{
    return h[r] - h[l - 1] * pw[r - l + 1];
}

void work()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> s[0][i];
    for(int i = 1; i <= m; ++i) cin >> s[1][i];
    iota(id + 1, id + n + 1, 1);
    sort(id + 1, id + n + 1, [&](int a, int b) {return s[0][a].size() < s[0][b].size();});
    for(int i = 1, len; i <= n; ++i)
    {
        build(0, id[i]);
        len = (int)s[0][id[i]].size();
        mp[0][calc(1, len)] = i;
        for(int j = 1; j < len; ++j) if(mp[0].count(calc(1, j))) st[0].insert(calc(j + 1, len));
    }
    iota(id + 1, id + m + 1, 1);
    sort(id + 1, id + m + 1, [&](int a, int b) {return s[1][a].size() < s[1][b].size();});
    for(int i = 1, len; i <= m; ++i)
    {
        build(1, id[i]);
        len = (int)s[1][id[i]].size();
        mp[1][calc(1, len)] = i;
        for(int j = 2; j <= len; ++j) if(mp[1].count(calc(j, len))) st[1].insert(calc(1, j - 1));
    }
    for(int i = 1, len; i <= n; ++i)
    {
        build(0, i);
        len = (int)s[0][i].size();
        for(int j = 1; j < len; ++j) if(mp[0].count(calc(1, j)) && st[1].count(calc(j + 1, len))) ans[0][i] = ans[0][mp[0][calc(1, j)]] = 1;
    }
    for(int i = 1, len; i <= m; ++i)
    {
        build(1, i);
        len = (int)s[1][i].size();
        for(int j = 2; j <= len; ++j) if(mp[1].count(calc(j, len)) && st[0].count(calc(1, j - 1))) ans[1][i] = ans[1][mp[1][calc(j, len)]] = 1;
    }
    int sum[2] = {0, 0};
    for(int i = 1; i <= n; ++i) if(!ans[0][i]) ++sum[0];
    for(int i = 1; i <= m; ++i) if(!ans[1][i]) ++sum[1];
    print(sum[0], ' '), print(sum[1], '\n');
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    int T; read(T);
//    for(int ca = 1; ca <= T; ++ca)
//    {
//        work();
//    }
    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


