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

int n, k;


void work()
{
    read(n), read(k);
    for(int i = 1; i <= n; ++i) g[i].clear();
    for(int i = 2, u, v; i <= n; ++i)
    {
        read(u), read(v);
        g[u].insert(v), g[v].insert(u);
    }
    unordered_set<int> s1, s2;
    for(int i = 1; i <= n; ++i) if(g[i].size() == 1) s1.insert(i);
    for(int i = 1; i <= k; ++i)
    {
        if(s1.empty()) continue;
        s2.clear();
        for(const auto& u: s1)
        {
            for(const auto)
        }
    }
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


