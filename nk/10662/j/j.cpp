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

const int M = (int)1e2;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

ll lim = (1ll<<60) - 1;
int n;
vector<int> g[M + 5];
bool gg[M + 5][M + 5];
vector<int> part[2];
ll a[M + 5];

void dfs(int u, int fa, int dep)
{
    part[dep].push_back(u);
    for(const int& v: g[u])
    {
        if(v == fa) continue;
        dfs(v, u, dep^1);
    }
}

void dfs2(int u, int fa)
{
    if(a[u] == 0)
    {
        for(const int& v: g[u])
        {
            for(int i = 0; i < 59; ++i) if(!(a[v]>>i&1)) a[u] |= (1ll<<i);
        }
    }
    a[u] ^= (1ll<<59);
    for(const int& v: g[u])
    {
        if(v == fa) continue;
        dfs2(v, u);
    }
}

void work()
{
    read(n);
    for(int i = 2, u, v; i <= n; ++i)
    {
        read(u), read(v);
        g[u].push_back(v), g[v].push_back(u);
        gg[u][v] = gg[v][u] = 1;
    }
    dfs(1, 0, 0);
    if(part[0].size() > part[1].size()) swap(part[0], part[1]);
    for(int i = 0; i < (int)part[0].size(); ++i) a[part[0][i]] = (lim^(1ll<<i));
    dfs2(1, 0);
    for(int i = 1; i <= n; ++i) print(a[i], i == n ? '\n' : ' ');
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


