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

int f[M + 5][M + 5][2][2];

int dfs(int n, int m, int s, int u)
{
    if(n == 0 || m == 0) return 0;
    if(f[n][m][s][u] != inf) return f[n][m][s][u];
    if(u == 0)
    {
        f[n][m][s][u] = -inf;
        for(int i = 1; i <= m; ++i)
            f[n][m][s][u] = max(f[n][m][s][u], dfs(n, m - i, s^(i&1), u^1) + ((i&1) && (n&1) ? (s == 1 ? 1 : -1) : 0));
    }
    else
    {
        for(int i = 1; i <= n; ++i)
            f[n][m][s][u] = min(f[n][m][s][u], dfs(n - i, m, s, u^1) - ((i&1) && (m&1) ? (s == 1 ? 1: -1) : 0));
    }
    return f[n][m][s][u];
}

void work()
{
    int n, m; read(n), read(m);
    memset(f, 0x3f, sizeof f);
    print(dfs(n, m, 1, 0), '\n');
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


