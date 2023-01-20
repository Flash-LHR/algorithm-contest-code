#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void scan(T &n)
{
    n = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {n = n * 10 + ch - '0'; ch = getchar();}
    if (f == -1) n = -n;
}

template <typename T, typename... A>
inline void scan(T &n, A&... a)
{
    scan(n), scan(a...);
}

template <typename T>
void print(T n)
{
    if (n < 0) putchar('-'), n = -n;
    if (n > 9) print(n / 10);
    putchar(n % 10 + '0');
}

template <typename T>
void print(T n, char ch)
{
    print(n), putchar(ch);
}

typedef double db;
typedef long long ll;
typedef unsigned long long ull;

const int M = (int)2e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = (int)1e9 + 7;

int dep[M + 5];
int val[M + 5];
vector<int> g[M + 5];

void dfs(int u)
{
    for (const int &v: g[u]) {
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}

void work()
{
    int n; scan(n);
    for (int i = 2, fa; i <= n; i++) {
        scan(fa);
        g[fa].push_back(i);
    }
    dep[1] = 1; dfs(1);
    sort(dep + 1, dep + n + 1);
    for (int i = 1; i <= n; i++) scan(val[i]);
    sort(val + 1, val + n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += (ll)dep[i] * val[i];
    print(ans, '\n');
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    int T = 1; //scan(T);
    for (int ca = 1; ca <= T; ++ca) {
        // printf("Case #%d: ", ca);
        work();
    }
    // cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}