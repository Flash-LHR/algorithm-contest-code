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
typedef unsigned long long ull;

const int MA = (int)1e3;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

struct HashTable
{
    ull H[MA + 5][MA + 5];
    ull b1 = 13331, b2 = 131;
    ull p1[MA + 5], p2[MA + 5];

    void init(int a[MA + 5][MA + 5], int n, int m)
    {
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) H[i][j] = H[i][j - 1] * b2 + a[i][j];
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) H[i][j] += H[i - 1][j] * b1;
        p1[0] = 1; for(int i = 1; i <= m; ++i) p1[i] = p1[i - 1] * b1;
        p2[0] = 1; for(int i = 1; i <= n; ++i) p2[i] = p2[i - 1] * b2;
    }

    ull getH(int sx, int sy, int tx, int ty)
    {
        return H[tx][ty] - H[tx][sy - 1] * p2[ty - sy + 1] - H[sx - 1][ty] * p1[tx - sx + 1] + H[sx - 1][sy - 1] * p1[tx - sx + 1] * p2[ty - sy + 1];
    }
} HT;

int len, v[MA + 5];
int st[MA + 5], tp;
int L[MA + 5], R[MA + 5];

ll cal()
{
    tp = 0;
    for(int i = 1; i <= len; ++i)
    {
        while(tp && v[st[tp]] >= v[i]) --tp;
        L[i] = (tp ? st[tp] + 1 : 1);
        st[++tp] = i;
    }

    tp = 0;
    for(int i = len; i >= 1; --i)
    {
        while(tp && v[st[tp]] > v[i]) --tp;
        R[i] = (tp ? st[tp] - 1 : len);
        st[++tp] = i;
    }
    
    ll ans = 0;
    for(int i = 1; i <= len; ++i) ans += 1ll * v[i] * (R[i] - i + 1) * (i - L[i] + 1);
    return ans;
}


int N, M, a[MA + 5][MA + 5];
int n, m, b[MA + 5][MA + 5];
int up[MA + 5][MA + 5];

void work()
{
    read(N), read(M); for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j) read(a[i][j]);
    read(n), read(m); for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) read(b[i][j]);
    HT.init(b, n, m); ull BH = HT.getH(1, 1, n, m); HT.init(a, N, M);
    ll ans = 0;
    for(int i = 1; i <= N - n + 1; ++i)
    {
        for(int j = 1; j <= M - m + 1; ++j) up[i][j] = (HT.getH(i, j, i + n - 1, j + m - 1) == BH ? (i - n >= 1 ? up[i - n][j] + 1 : 1) : 0);
        for(int j = 1; j <= m; ++j)
        {
            len = 0; for(int k = j; k <= M; k += m) v[++len] = up[i][k];
            ans += cal();
        }
    }
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


