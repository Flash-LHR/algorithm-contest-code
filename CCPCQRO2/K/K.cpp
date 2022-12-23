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
vector<int> g[M + 5], gg[M + 5];
int fa[M + 5], a[M + 5], id[M + 5], dep[M + 5];
bool vis[M + 5];

int tofind(int x) {return x == fa[x] ? x : fa[x] = tofind(fa[x]);}

void dfs(int u) {for(const auto& v: gg[u]) {dep[v] = dep[u] + 1; dfs(v);}}

void work()
{
    read(n); for(int i = 1; i <= n; ++i) g[i].clear(), gg[i].clear(), vis[fa[i] = i] = 0;
	for(int i = 2, u, v; i <= n; ++i)
	{
		read(u), read(v);
		g[u].push_back(v), g[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i) read(a[i]), id[i] = i;
	sort(id + 1, id + n + 1, [&](int x, int y) {return a[x] < a[y];});
	for(int i = 1, u; i <= n; ++i)
	{
		u = id[i];
		for(const auto& v: g[u])
		{
			if(!vis[v]) continue;
			int ff = tofind(v);
			fa[ff] = u, gg[u].push_back(ff);
		}
		vis[u] = 1;
	}
	dep[id[n]] = 1; dfs(id[n]);
	for(int i = 1; i <= n; ++i) print(dep[i], '\n');
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


