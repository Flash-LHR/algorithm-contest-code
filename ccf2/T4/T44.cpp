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
    tuple<ull, ll, ll> H[MA + 5][MA + 5];
    ll b1 = 13331, b2 = 131, md1 = (ll)1e9 + 7, md2 = (ll)1e9 + 9;
    tuple<ull, ll, ll> p1[MA + 5], p2[MA + 5];

    void init(int a[MA + 5][MA + 5], int n, int m)
    {
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
            get<0>(H[i][j]) += get<0>(H[i - 1][j]) * b1;
            (get<1>(H[i][j]) += get<1>(H[i - 1][j]) * b1 % md1) %= md1;
            (get<2>(H[i][j]) += get<2>(H[i - 1][j]) * b1 % md2) %= md2;
            continue;
            auto& [x, y, z] = H[i][j - 1];
            auto& [xx, yy, zz] = H[i][j];
            xx = x * b2 + a[i][j];
            yy = (y * b2 % md1 + a[i][j]) % md1;
            zz = (z * b2 % md2 + a[i][j]) % md2;
        }
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
            auto& [x, y, z] = H[i][j - 1];
            auto& [xx, yy, zz] = H[i][j];
            xx += x * b1;
            (yy += y * b1 % md1) %= md1;
            (zz += z * b1 % md2) %= md2;
        }
        get<0>(p1[0]) = get<1>(p1[0]) = get<2>(p1[0]) = 1;
        //p1[0] = make_tuple(1, 1, 1);
        for(int i = 1; i <= m; ++i) {
            get<0>(p1[i]) = get<0>(p1[i - 1]) * b1;
            get<1>(p1[i]) = get<1>(p1[i - 1]) * b1 % md1;
            get<2>(p1[i]) = get<2>(p1[i - 1]) * b1 % md2;
        }
        get<0>(p2[0]) = get<1>(p2[0]) = get<2>(p2[0]) = 1;
        //p2[0] = make_tuple(1, 1, 1);
        for(int i = 1; i <= n; ++i) {
            get<0>(p2[i]) = get<0>(p2[i - 1]) * b2;
            get<1>(p2[i]) = get<1>(p2[i - 1]) * b2 % md1;
            get<2>(p2[i]) = get<2>(p2[i - 1]) * b2 % md2;
        }
    }

    tuple<ull, ll, ll> getH(int sx, int sy, int tx, int ty)
    {
        tuple<ull, ll, ll> h;
        get<0>(h) = get<0>(H[tx][ty]) - get<0>(H[tx][sy - 1]) * get<0>(p2[ty - sy + 1]) - get<0>(H[sx - 1][ty]) * get<0>(p1[tx - sx + 1]) + get<0>(H[sx - 1][sy - 1]) * get<0>(p1[tx - sx + 1]) * get<0>(p2[ty - sy + 1]);
        get<1>(h) = get<1>(H[tx][ty]) - get<1>(H[tx][sy - 1]) * get<1>(p2[ty - sy + 1]) % md1 - get<1>(H[sx - 1][ty]) * get<1>(p1[tx - sx + 1]) % md1 + get<1>(H[sx - 1][sy - 1]) * get<1>(p1[tx - sx + 1]) % md1 * get<1>(p2[ty - sy + 1]) % md1;
        get<2>(h) = get<2>(H[tx][ty]) - get<2>(H[tx][sy - 1]) * get<2>(p2[ty - sy + 1]) % md2 - get<2>(H[sx - 1][ty]) * get<2>(p1[tx - sx + 1]) % md2 + get<2>(H[sx - 1][sy - 1]) * get<2>(p1[tx - sx + 1]) % md2 * get<2>(p2[ty - sy + 1]);
        get<1>(h) = (get<1>(h) % md1 + md1) % md1, get<2>(h) = (get<2>(h) % md2 + md2) % md2;
        return h;
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
    HT.init(b, n, m); tuple<ull, ll, ll> BH = HT.getH(1, 1, n, m); HT.init(a, N, M);
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



