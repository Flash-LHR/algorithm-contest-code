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

const db eps = 1e-12;
const int M = (int)1e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n;
db ansx, x[M + 5], y[M + 5];

double check(double mid)
{
    double l = -1e18, r = 1e18, d;
    for(int i = 1; i <= n; ++i)
    {
        if(mid < fabs(y[i])) return 0;
        d = sqrt(mid * mid - y[i] * y[i]);
        l = max(l, x[i] - d), r = min(r, x[i] + d);
        if(l > r) return 0;
    }
    ansx = l;
    return 1;
}

void work()
{
    while(~scanf("%d", &n) && n)
    {
        for(int i = 1; i <= n; ++i) scanf("%lf%lf", &x[i], &y[i]);
        double l = 0.0, r = 1e9, mid;
        for(int i = 1; i <= 100; ++i)
        {
            mid = (l + r) / 2.0;
            if(check(mid)) r = mid;
            else           l = mid;
        }
        check(r);
        printf("%.9f %.9f\n", ansx, r);
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


