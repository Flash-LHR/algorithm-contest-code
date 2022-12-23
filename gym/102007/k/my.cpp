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

const int M = (int)1e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n, h;
vector<int> g[M + 5], v1, leaf;
vector<pair<int, int>> v2, ans;

void dfs(int u, int fa)
{
    for(const int& v: g[u])
    {
        if(v == fa) continue;
        dfs(v, u);
    }
    if(g[u].size() == 1) leaf.push_back(u);
}

void work()
{
    read(n), read(h);
    for(int i = 2, a, b; i <= n; ++i)
    {
        read(a), read(b);
        g[a].push_back(b), g[b].push_back(a);
    }
    if(n == 2)
    {
        print(1, '\n');
        //print(0, ' '), print(1, '\n');
        return;
    }
    for(int i = 0; i < n; ++i) if(g[i].size() > g[h].size()) h = i;
    for(const int& v: g[h])
    {
        dfs(v, h);
        if(leaf.size()&1)
        {
            v1.push_back(leaf.back());
            leaf.pop_back();
        }
        else
        {
            int a = leaf.back(); leaf.pop_back();
            int b = leaf.back(); leaf.pop_back();
            v2.push_back(make_pair(a, b));
        }
        while(!leaf.empty())
        {
            int a = leaf.back(); leaf.pop_back();
            int b = leaf.back(); leaf.pop_back();
            ans.push_back(make_pair(a, b));
        }
    }
    while(v2.size() > 2)
    {
        auto p1 = v2.back(); v2.pop_back();
        auto p2 = v2.back(); v2.pop_back();
        auto p3 = v2.back(); v2.pop_back();
        ans.push_back(make_pair(p1.first, p2.first));
        ans.push_back(make_pair(p3.first, p2.second));
        v1.push_back(p1.second), v1.push_back(p3.second);
    }
    while(v2.size() > 1)
    {
        auto p1 = v2.back(); v2.pop_back();
        auto p2 = v2.back(); v2.pop_back();
        ans.push_back(make_pair(p1.first, p2.first));
        ans.push_back(make_pair(p1.second, p2.second));
    }
    if(v2.size() && v1.size())
    {
        auto p = v2.back(); v2.pop_back();
        int a = v1.back(); v1.pop_back();
        ans.push_back(make_pair(p.first, a));
        v1.push_back(p.second);
    }
    while(v1.size() > 1)
    {
        int a = v1.back(); v1.pop_back();
        int b = v1.back(); v1.pop_back();
        ans.push_back(make_pair(a, b));
    }
    if(v1.size())
    {
        int a = v1.back(); v1.pop_back();
        ans.push_back(make_pair(a, h));
    }
    if(v2.size())
    {
        auto p = v2.back();
        ans.push_back(make_pair(p.first, h));
        ans.push_back(make_pair(p.second, h));
    }
    print(ans.size(), '\n');
    //for(const auto& p: ans) print(p.first, ' '), print(p.second, '\n');
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
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


