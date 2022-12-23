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

const int M = (int)1e6;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n, a[M + 5], b[M + 5];
ll pre[M + 5], suf[M + 5];

void work()
{
    read(n); for(int i = 1; i <= n; ++i) read(a[i]);
    memcpy(b, a, sizeof(a));
    pre[0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(b[i] >= 0) pre[i] = pre[i - 1] + b[i], b[i + 2] -= b[i], b[i + 1] -= b[i], b[i] -= b[i];
        else pre[i] = pre[i - 1];
    }
    memcpy(b, a, sizeof(a));
    suf[n + 1] = 0;
    for(int i = n; i >= 1; --i)
    {
        if(b[i] >= 0) suf[i] = suf[i + 1] + b[i], b[i - 2] -= b[i], b[i - 1] -= b[i], b[i] -= b[i];
        else suf[i] = suf[i + 1];
    }
    ll mi = (ll)1e18;
    for(int i = 2; i <= n; ++i)
    {
        mi = min(mi, pre[i - 2] + suf[i + 1]);
    }
    print(mi, '\n');
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


