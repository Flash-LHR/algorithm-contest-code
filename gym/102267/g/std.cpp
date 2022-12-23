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

int n;
ll a[M + 5], b[M + 5];
ll c[M + 5];

void work()
{
    read(n);
    for(int i = 1; i <= n; ++i) read(a[i]), read(b[i]), c[i] = 1;
    int q; read(q);
    for(int i = 1; i <= q; ++i)
    {
        int op; read(op);
        if(op == 1)
        {
            ll x; read(x);
            ll die = 0, hug = 0;
            for(int i = 1; i <= n; ++i)
            {
                if(c[i] == 0) continue;
                if(x >= a[i])
                {
                    x -= a[i];
                    if(x > b[i]) ++die, c[i] = 0;
                }
                else
                {
                    for(int j = i; j <= n; ++j) if(c[j]) ++hug;
                    break;
                }
            }
            printf("%lld %lld\n", die, hug);
        }
        else if(op == 2)
        {
            ll a, b, c; read(a), read(b), read(c);
            ::a[c] = a, ::b[c] = b, ::c[c] = 1;
        }
    }
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


