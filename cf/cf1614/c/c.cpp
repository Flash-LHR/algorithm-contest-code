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

const int M = (int)2e5;
const int N = (int)30;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n, m;
int a[N + 5][M + 5];
int fa[N + 5][M + 5];

int tofind(int j, int x)
{
    if(x == fa[j][x]) return x;
    return fa[j][x] = tofind(j, fa[j][x]);
}

void Union(int j, int a, int b)
{
    a = tofind(j, a), b = tofind(j, b);
    if(a != b) fa[j][a] = b;
}

void work()
{
    read(n), read(m);
    for(int i = 1; i <= n; ++i) for(int j = 0; j <= N; ++j) a[j][i] = 1, fa[j][i] = i;
    for(int i = 1, l, r, x; i <= m; ++i)
    {
        read(l), read(r), read(x);
        for(int j = N; j >= 0; --j)
        {
            if(x>>j&1) continue;
            int ll = l;
            a[j][ll] = 0;
            while(fa[j][ll] + 1 <= r)
            {
                Union(j, ll, fa[j][ll] + 1);
                ll = fa[j][ll];
                a[j][ll] = 0;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= N; ++i)
    {
       int cnt[2] = {1, 0};
       for(int j = 1; j <= n; ++j)
       {
           int back[2] = {cnt[0], cnt[1]};
           cnt[0] = (back[0] + back[a[i][j]]) % mod;
           cnt[1] = (back[1] + back[a[i][j]^1]) % mod;
       }
       (ans += (1ll<<i) * cnt[1] % mod) %= mod;
    }
    print(ans, '\n');
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int T; read(T);
    for(int ca = 1; ca <= T; ++ca)
    {
        work();
    }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


