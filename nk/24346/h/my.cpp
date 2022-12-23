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

int n, m;
int head[M + 5], ecnt;
struct enode
{
    int v, nx, w, bri;
} Edge[M * 4 + 5];

int dfn[M + 5], low[M + 5], dfnnum;
int sz[M + 5];

void init()
{
    ecnt = 0;
    for(int i = 1; i <= n; ++i)
    {
        head[i] = -1;
    }
}

void add(int u, int v, int w)
{
    Edge[ecnt].v = v;
    Edge[ecnt].w = w;
    Edge[ecnt].bri = 0;
    Edge[ecnt].nx = head[u];
    head[u] = ecnt++;
}

void tarjan(int u, int in_edge)
{
    dfn[u] = low[u] = ++dfnnum;
    for(int i = head[u]; ~i; i = Edge[i].nx)
    {
        int v = Edge[i].v;
        if(!dfn[v])
        {
            tarjan(v, i);
            sz[u] += sz[v];
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]) Edge[i].bri = Edge[i^1].bri = 1;
        }
        else if(i != (in_edge^1))
        {
            low[u] = min(low[u], dfn[v]);
        }
        if(dfn[u] < dfn[v]) ++sz[u];
    }
}

void work()
{
    read(n), read(m); init();
    ll s = 0;
    for(int i = 1, u, v, w; i <= m; ++i)
    {
        read(u), read(v), read(w);
        add(u, v, w), add(v, u, w);
        s += w;
    }
    if(m & 1)
    {
        tarjan(1, -1); ll ans = 0;
        //for(int i = 1; i <= n; ++i) printf("sz[%d]=%d\n", i, sz[i]);
        for(int i = 0; i < ecnt; i += 2)
        {
            if(Edge[i].bri)
            {
                int u = Edge[i].v, v = Edge[i^1].v;
                if(dfn[u] > dfn[v]) swap(u, v);
                if(!(sz[v]&1)) ans = max(ans, s - Edge[i].w);
            }
            else ans = max(ans, s - Edge[i].w);
        }
        print(ans, '\n');
    }
    else print(s, '\n');
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


