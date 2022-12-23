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

unordered_map<ll, ll> f[15][15*15];
int num[15], pos;
int cnt[10];

ll Hash()
{
    ll s = 0;
    for(int i = 0; i < 10; ++i) s = s * 15 + cnt[i];
    return s;
}

ll dfs(int pos, int ord, bool lim, bool lea)
{
    if(pos == -1) return ord;
    ll H = Hash();
    if(!lim && !lea && f[pos][ord].count(H)) return f[pos][ord][H];
    int up = (lim ? num[pos] : 9); ll res = 0;
    for(int i = 0; i <= up; ++i)
    {
        int add = 0; for(int j = 0; j < i; ++j) add += cnt[j];
        if(!(lea && i == 0)) ++cnt[i];
        res += dfs(pos - 1, ord + add, lim && (i == up), lea && (i == 0));
        if(!(lea && i == 0)) --cnt[i];
    }
    if(!lim && !lea) f[pos][ord][H] = res;
    //printf("\t\tpos=%d ord=%d lim=%d lea=%d res=%lld\n", pos, ord, lim, lea, res);
    return res;
}

ll cal(ll n)
{
    if(n == 0) return 0;
    pos = 0;
    while(n)
    {
        num[pos++] = n % 10;
         n /= 10;
    }
    return dfs(pos - 1, 0, 1, 1);
}

void work()
{
    ll l, r; read(l), read(r);
    print(cal(r) - cal(l - 1), '\n');
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
        printf("Case %d: ", ca);
        work();
    }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


