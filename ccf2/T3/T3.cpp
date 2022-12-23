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
typedef __int128 ll;

const int M = (int)1e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

struct GETPHI
{
    typedef __int128 ll;

    ll gcd(ll a, ll b)
    {
        return b ? gcd(b, a % b) : a;
    }

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

    ll f(ll x, ll c, ll n)
    {
        return (mul(x, x, n) + c) % n;
    }

    int Rand()
    {
        return rand()<<15^rand();
    }

    ll llRand()
    {
        return (ll)Rand()<<30^Rand();
    }

    ll Pollard_Rho(ll n)
    {
        ll s = 0, t = 0, c = llRand() % (n - 1) + 1, val = 1, d;
        for(int i = 1; ; i *= 2, s = t, val = 1)
        {
            for(int j = 1; j <= i; ++j)
            {
                t = f(t, c, n);
                val = mul(val, t > s ? t - s : s - t, n);
                if(!(j & 127))
                {
                    d = gcd(val, n);
                    if(d > 1) return d;
                }
            }
            d = gcd(val, n);
            if(d > 1) return d;
        }
    }

    vector<ll> dv;
    map<ll, ll> mp;

    void div(ll n)
    {
        if(Miller_Rabin(n))
        {
            dv.push_back(n);
            return;
        }
        ll p = n;
        while(p >= n)     p = Pollard_Rho(n);
        while(n % p == 0) n /= p;
        if(n > 1) div(n);
        if(p > 1) div(p);
    }

    ll getPhi(ll n)
    {
        if(mp.count(n)) return mp[n];
        ll m = n;
        dv.clear();
        div(n);
        sort(dv.begin(), dv.end());
        dv.erase(unique(dv.begin(), dv.end()), dv.end());
        for(const ll& d: dv) n = n / d * (d - 1);
        return mp[m] = n;
    }
} PR;

ll Mod(ll n, ll m)
{
    return n < m ? n : n % m + m;
}

ll quick(ll a, ll b, ll p)
{
    ll s = 1;
    while(b)
    {
        if(b & 1) s = Mod(s * a, p);
        a = Mod(a * a, p);
        b >>= 1;
    }
    return s;
}

ll cal(ll a, ll s, ll m)
{
    if(s == 1 || m == 1) return Mod(a, m);
    return quick(a, cal(a, s - 1, PR.getPhi(m)), m);
}

void work()
{
    ll a, s, m; read(a), read(s), read(m);
    ll ans = 0, cur = 0;
    int mi = min(s, (ll)100);
    for(int i = 1; i <= mi; ++i)
    {
        cur = cal(a, i, m) % m;
        (ans += cur) %= m;
        if(i == mi) (ans += (s - mi) % m * cur % m) %= m;
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
    srand(time(NULL));
    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


