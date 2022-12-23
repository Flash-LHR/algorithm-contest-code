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

int n, m;
vector<pair<int, int>> g[M + 5];
int col[M + 5], cnt[30], sz;

bool dfs(int u)
{
    ++sz;
    for(auto [v, w]: g[u])
    {
        if(~col[v])
        {
            if((col[v]^col[u]) != w) return 0;
        }
        else
        {
            col[v] = (col[u]^w);
            for(int i = 0; i < 30; ++i) if((col[v]>>i)&1) ++cnt[i];
            if(!dfs(v)) return 0;
        }
    }
    return 1;
}

void work()
{
    read(n), read(m);
    for(int i = 1, u, v, w; i <= m; ++i)
    {
        read(u), read(v), read(w);
        g[u].emplace_back(v, w), g[v].emplace_back(u, w);
    }
    memset(col, -1, sizeof col);
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(~col[i]) continue;
        col[i] = sz = 0; memset(cnt, 0, sizeof cnt);
        if(!dfs(i))
        {
            print(-1, '\n');
            return;
        }
        for(int i = 0; i < 30; ++i) ans += (1ll<<i) * min(cnt[i], sz - cnt[i]);
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


