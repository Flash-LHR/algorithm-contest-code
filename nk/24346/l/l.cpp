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

const int M = (int)4e3;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)998244353;

int n;
vector<int> g[M + 5];
int sz[M + 5];
int f[M + 5][M / 2 + 5][2];
int back[M + 5][2];
int h[M + 5];

void dfs(int u, int fa)
{
    f[u][0][0] = 1, sz[u] = 1;
    for(const int& v: g[u])
    {
        if(v == fa) continue;
        dfs(v, u);
        for(int i = 0; i <= sz[u] / 2; ++i) back[i][0] = f[u][i][0], back[i][1] = f[u][i][1];
        for(int i = 0; i <= sz[u] / 2; ++i)
        {
            for(int j = 0; j <= sz[v] / 2; ++j)
            {
                if(j) {
                (f[u][i + j][0] += 1ll * (f[v][j][0] + f[v][j][1]) * back[i][0] % mod) %= mod;
                (f[u][i + j][1] += 1ll * (f[v][j][0] + f[v][j][1]) * back[i][1] % mod) %= mod;
                }
                (f[u][i + j + 1][1] += 1ll * f[v][j][0] * back[i][0] % mod) %= mod;
            }
        }
        sz[u] += sz[v];
    }
    /*for(int i = 0; i <= sz[u]; ++i) printf("f[%d][%d][0]=%d f[%d][%d][1]=%d\n", u, i, f[u][i][0], u, i, f[u][i][1]);
    printf("\n");*/
}

void work()
{
    read(n);
    for(int i = 1, u, v; i < 2 * n; ++i)
    {
        read(u), read(v);
        g[u].push_back(v), g[v].push_back(u);
    }
    dfs(1, 0);
    h[0] = 1;
    for(int i = 1; i <= n; ++i) h[i] = 1ll * h[i - 1] * (2 * i - 1) % mod;
    int ans = 0;
    for(int i = 0; i <= n; ++i) (ans += -(ll)((i&1) * 2 - 1) * (f[1][i][0] + f[1][i][1]) * h[n - i] % mod) %= mod;
    ans = (ans % mod + mod) % mod;
    print(ans, '\n');
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


