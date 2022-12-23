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
struct node
{
    int l, r;
    bool operator<(const node& b) const
    {
        if(r != b.r) return r < b.r;
        return l > b.l;
    }
} s[M + 5];

void work()
{
    read(n);
    for(int i = 1; i <= n; ++i) read(s[i].l), read(s[i].r);
    sort(s + 1, s + n + 1);
    ll ans = 0, p = 0;
    for(int l = 1, r = 0; l <= n; l = r + 1)
    {
        while(r < n && s[r + 1].r == s[l].r) p = max(p, (ll)s[++r].l);
        ans += (r - l + 1) * p;
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


