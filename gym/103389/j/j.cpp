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
const int N = (int)1e2;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n, k, p;
vector<pair<int, int>> g[M + 5];
int sz[M + 5];
ll f[M + 5][N * 2 + 5][2], back[N * 2 + 5][2];

void dfs(int u, int fa)
{
    f[u][1][0] = 0;
    f[u][0][1] = 0;
    sz[u] = 1;
    for(const auto& [v, w]: g[u])
    {
        if(v == fa) continue;
        dfs(v, u);
        for(int j = 0; j <= sz[u]; ++j) for(int k = 0; k < 2; ++k) back[j][k] = f[u][j][k];
        for(int j = 0; j <= sz[u]; ++j)
        {
            for(int k = 0; k <= sz[v] && j + k <= ::k * 2; ++k)
            {
                f[u][j + k][0] = max(f[u][j + k][0],
                                     max(back[j][1] + f[v][k][1],
                                         back[j][0] + f[v][k][0] + w));
                f[u][j + k][1] = max(f[u][j + k][1], back[j][1] + f[v][k][0]);
            }
        }
        sz[u] += sz[v];
    }
    /*for(int i = 0; i <= sz[u]; ++i)
    {
        printf("f[%d][%d]: %lld %lld %lld %lld\n", u, i, f[u][i][0], f[u][i][1], f[u][i][2], f[u][i][3]);
    }*/
}

void work()
{
    read(n), read(k), read(p);
    memset(f, -0x3f, sizeof f);
    for(int i = 2, u, v, w; i <= n; ++i)
    {
        read(u), read(v), read(w);
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    dfs(1, 0);
    ll mx = 0;
    for(int i = 0; i <= min(n / 2, k); ++i)
    {
        mx = max(mx, f[1][i][0] + i * p);
    }
    print(mx, '\n');
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


