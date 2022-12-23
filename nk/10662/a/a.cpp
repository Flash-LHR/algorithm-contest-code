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

const int M = (int)2e2;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)998244353;

int n;
bool a[M + 5][M + 5];
bool b[M + 5][M + 5];
bool g[M + 5][M + 5];

ll quick(ll a, ll b, ll p = mod)
{
    ll s = 1;
    while(b)
    {
        if(b & 1) s = s * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return s % p;
}

void build(int c)
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j) g[i][j] = a[i][j];
        if(b[i][c] & 1) g[i][i] ^= 1;
    }
}

int TLE = 0;

int guass(int n, int m)
{
    int c, r;
    for(c = 1, r = 1; c <= m; ++c)
    {
        int t = r;
        for(int i = r; i <= n; ++i) if(g[i][c]) t = i;
        if(!g[t][c]) continue;
        for(int i = c; i <= m + 1; ++i) swap(g[t][i], g[r][i]);
        for(int i = 1; i <= n; ++i)
        {
            if(i == r) continue;
            if(g[i][c])
            {
                for(int j = m + 1; j >= c; --j) g[i][j] ^= g[r][j], ++TLE;
            }
        }
        ++r;
    }
    for(int i = r; i <= n; ++i) if(g[i][m + 1]) return -1;
    return m - r + 1;

}

void work()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) scanf("%d", &b[i][j]);
    ll ans = 1;
    for(int j = 1; j <= n; ++j)
    {
        build(j);
        int r = guass(n, n);
        if(r == -1) {ans = 0; break;}
        (ans *= quick(2, r)) %= mod;
    }
    printf("%lld\n", ans);
    cerr << "TLE = " << TLE << "\n";
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


