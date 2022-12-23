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

int n, a[M + 5];
ll Lcm[M + 5];

void work()
{
    read(n);
    for(int i = 1; i <= n; ++i)
    {
        read(a[i]);
    }
    bool f = 1;
    for(int i = 1; i <= n; ++i)
    {
        bool g = 0;
        if(i + 1 <= 23 && a[i] % Lcm[i + 1] == 0) g = 1;
        if(g) f = 0;
    }
    puts(!f ? "NO" : "YES");
}

ll _lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    Lcm[1] = 1;
    for(int i = 2; i <= 23; ++i) Lcm[i] = _lcm(Lcm[i - 1], i);
    //for(int i = 1; i <= 23; ++i) printf("lcm[%d]=%lld\n", i, Lcm[i]);
    int T; read(T);
    for(int ca = 1; ca <= T; ++ca)
    {
        work();
    }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


