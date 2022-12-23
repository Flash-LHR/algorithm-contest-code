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

const int M = (int)5e2;;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, m;
int a[M + 5], id[M + 5];
ll f[M + 5][M + 5], g[M + 5][M + 5];

void work()
{
    read(n), read(m);
    memset(f, 0x3f, sizeof f);
    memset(g, 0x3f, sizeof g);
    for(int i = 1; i <= n; ++i) read(a[i]), id[i] = i, f[i][i] = g[i][i] = 0;
    sort(id + 1, id + n + 1, [&](int x, int y){return a[x] < a[y];});
    for(int i = 1, u, v, w; i <= m; ++i)
    {
        read(u), read(v), read(w);
        f[u][v] = f[v][u] = min(f[u][v], 1ll * max(a[u], a[v]) * w);
        g[u][v] = g[v][u] = min(g[u][v], 1ll * w);
    }
    for(int k = 1; k <= n; ++k)
    {
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                g[id[i]][id[j]] = min(g[id[i]][id[j]], max(g[id[i]][id[k]], g[id[k]][id[j]]));
                f[id[i]][id[j]] = min(f[id[i]][id[j]], g[id[i]][id[j]] * max({a[id[i]], a[id[k]], a[id[j]]}));
            }
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            print(f[i][j] >= linf / 2 ? -1 : f[i][j], j == n ? '\n' : ' ');
        }
    }
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


