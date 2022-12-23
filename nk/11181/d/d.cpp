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

const int M = (int)5e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n;
ll a[4][M + 5];
ll s[4][M + 5];
ll b[M + 5];
ll d[M * 10 + 5]; int m;

struct TA
{
    int n; ll tree[M * 10 + 5];
    void init(int _n) {n = _n; for(int i = 0; i <= n; ++i) tree[i] = 0;}
    inline int lowbit(int n) {return n&-n;}
    void add(int a, ll b) {for(int i = a; i <= n; i += lowbit(i)) tree[i] += b;}
    ll ask(int r) {ll s = 0; for(int i = r; i; i -= lowbit(i)) s += tree[i]; return s;}
    ll ask(int l, int r) {return ask(r) - ask(l - 1);}
} tr;

int id(ll x)
{
    return lower_bound(d + 1, d + m + 1, x) - d;
}

void work()
{
    read(n); m = 0;
    for(int i = 1; i <= 3; ++i) for(int j = 1; j <= n; ++j) read(a[i][j]);
    for(int i = 1; i <= 3; ++i)
    {
        for(int j = 1; j <= n; ++j) s[i][j] = s[i][j - 1] + a[i][j];
    }
    for(int i = 1; i <= n; ++i) b[i] = -s[2][i] + s[3][i - 1], d[++m] = b[i];
    for(int i = 1; i <= n; ++i) d[++m] = s[1][i] - s[2][i - 1] + s[3][n];
    sort(d + 1, d + m + 1); m = unique(d + 1, d + m + 1) - (d + 1);
    tr.init(m);
    //for(int i = 1; i <= n; ++i) printf("b[%d]=%lld\n", i, b[i]);
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        tr.add(id(b[i]), 1);
        int p = id(s[1][i] - s[2][i - 1] + s[3][n]);
        //printf("i=%d x=%lld\n", i, s[1][i] - s[2][i - 1] + s[3][n]);
        ans += tr.ask(p);
        //printf("p=%d\n", p);
        //printf("idb=%d\n", id(b[i]));
    }
    print(ans % mod, '\n');
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


