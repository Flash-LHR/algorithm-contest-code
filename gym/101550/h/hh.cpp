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

const int M = (int)1e6;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

pair<int, int> p[M + 5];
int d[M + 5], m;
vector<int> g[M + 5];
bool vis[M + 5];
bool vis2[M + 5];

void dfs(int u, int& ver, int& edg)
{
    vis[u] = 1, ++ver, edg += (int)g[u].size();
    for(const int& v: g[u]) if(!vis[v]) dfs(v, ver, edg);
}

ll dfs1(int u)
{
    vis2[u] = 1;
    ll ans = 1ll * (g[u].size() - 1) * d[u];
    for(const int& v: g[u]) if(!vis2[v]) ans += dfs1(v);
    return ans;
}

ll f[M + 5][2];

void dfs2(int u, int fa)
{
    f[u][0] = f[u][1] = 0;
    for(const int& v: g[u])
    {
        if(v == fa) continue;
        dfs2(v, u);
        f[u][1] += f[v][1];
    }
    f[u][0] = max(f[u][0], f[u][1]);
    for(const int& v: g[u])
    {
        if(v == fa) continue;
        f[u][0] = max(f[u][0], f[u][1] - f[v][1] + f[v][0]);
    }
    f[u][0] += d[u], f[u][1] += d[fa];
    //printf("f[%d][0]=%lld f[%d][1]=%lld\n", u, f[u][0], u, f[u][1]);
}

ll Tree(int rt)
{
    //printf("rt=%d\n", rt);
    dfs2(rt, 0);
    return f[rt][0] - d[rt];
}

void work()
{
    int n; read(n); m = 0;
    for(int i = 1; i <= n; ++i)
    {
        read(p[i].first), read(p[i].second);
        d[++m] = p[i].first, d[++m] = p[i].second;
    }
    sort(d + 1, d + m + 1);
    m = unique(d + 1, d + m + 1) - (d + 1);
    for(int i = 1, u, v; i <= n; ++i)
    {
        u = lower_bound(d + 1, d + m + 1, p[i].first) - d;
        v = lower_bound(d + 1, d + m + 1, p[i].second) - d;
        g[u].push_back(v), g[v].push_back(u);
        //printf("u=%d v=%d\n", u, v);
    }
    ll ans = 0;
    for(int i = 1; i <= m; ++i)
    {
        if(vis[i]) continue;
        int ver = 0, edg = 0;
        //printf("i=%d\n", i);
        dfs(i, ver, edg);
        //printf("ver=%d edg=%d\n", ver, edg);
        if(ver * 2 == edg)          ans += dfs1(i);
        else if(ver * 2 - 2 == edg) ans += Tree(i);
    }
    print(ans, '\n');
}

int main()
{
    //cout << (sizeof(p) + sizeof(d) + sizeof(vis) + sizeof(vis2) + sizeof(f)) / 1024 / 1024 << "\n";
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


