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
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

ll mul(ll a, ll b, ll p)
{
    return (a * b - (ll)((long double)a / p * b) * p + p) % p;
}

ll quick(ll a, ll b, ll p)
{
    ll s = 1;
    while(b)
    {
        if(b & 1) s = mul(s, a, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return s;
}

bool Miller_Rabin(ll n, int c = 20)
{
    if(n == 2)            return 1;
    if(n < 2 || !(n & 1)) return 0;
    srand(time(NULL));
    ll m = n - 1, k = 0;
    while(!(m & 1)) k++, m >>= 1;
    ll a, x, y;
    for(int i = 1; i <= c; ++i)
    {
        a = rand() % (n - 1) + 1;
        x = quick(a, m, n);
        for(int j = 1; j <= k; ++j)
        {
            y = mul(x, x, n);
            if(y == 1 && x != 1 && x != n - 1) return 0;
            x = y;
        }
        if(y != 1) return 0;
    }
    return 1;
}

ll f(ll n)
{
	++n;
	while(!Miller_Rabin(n)) ++n;
	return n;
}

void work()
{
	ll n; read(n);
//	n = (f(n) + f(f(n))) / 2;
//	puts(Miller_Rabin(n) ? "YES" : "NO");
	puts(n == 1 ? "YES" : "NO");
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


