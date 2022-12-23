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

int m; ll L;
int a[M + 5];

bool check(int x, int y, int z)
{
    for(int i = 0; i < m; ++i)
    {
        int xx = x + i;
        if(xx < (1<<7))
        {
            if((__builtin_popcount(xx) + z) % 2 != a[i]) return 0;
        }
        else
        {
            if((__builtin_popcount(xx % (1<<7)) + z - y + 1) % 2 != a[i]) return 0;
        }
    }
    return 1;
}

int num[60];
ll f[60][1<<7][2][2];

ll dfs(int pos, int x, int y, int z, bool lim)
{
    if(pos == -1) return check(x, y, z);
    if(!lim && ~f[pos][x][y][z]) return f[pos][x][y][z];
    int up = (lim ? num[pos] : 1); ll res = 0;
    for(int i = 0; i <= up; ++i)
    {
        if(pos < 7) res += dfs(pos - 1, x + i * (1<<pos), y, z, lim && (i == up));
        else res += dfs(pos - 1, x, i ? (y^1) : 0, z^i, lim && (i == up));
    }
    if(!lim) f[pos][x][y][z] = res;
    return res;
}

ll cal(ll n)
{
    int pos = 0;
    while(n)
    {
        num[pos++] = (n&1);
        n>>=1;
    }
    return dfs(pos - 1, 0, 0, 0, 1);
}

void work()
{
    read(m), read(L);
    memset(f, -1, sizeof f);
    for(int i = 0; i < m; ++i) read(a[i]);
    print(cal(L), '\n');
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


