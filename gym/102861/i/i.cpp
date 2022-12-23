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

int n, cnt;
int head[M + 5];
struct enode
{
	int v, nx;
} Edge[M + 5];

int f[M + 5][2];
int a[M + 5], b[M + 5];
int pre[M + 5], suf[M + 5];

void init()
{
	cnt = 0;
	for(int i = 1; i <= n; ++i)
	{
		head[i] = -1;
	}
}

void add(int u, int v)
{
	Edge[cnt].v = v;
	Edge[cnt].nx = head[u];
	head[u] = cnt++;
}

void dfs(int u)
{
	if(head[u] == -1)
	{
		f[u][0] = 1, f[u][1] = 1;
		return;
	}
	for(int i = head[u]; ~i; i = Edge[i].nx) dfs(Edge[i].v);
	int m = 0;
    for(int i = head[u]; ~i; i = Edge[i].nx)
	{
		int v = Edge[i].v;
		a[++m] = f[v][0], b[m] = f[v][1];
	}
	pre[0] = 1; for(int i = 1; i <= m; ++i) pre[i] = 1ll * pre[i - 1] * a[i] % mod;
	suf[m + 1] = 1; for(int i = m; i >= 1; --i) suf[i] = 1ll * suf[i + 1] * a[i] % mod;
	f[u][0] = pre[m], f[u][1] = 0;
	for(int i = 1; i <= m; ++i) (f[u][1] += 1ll * pre[i - 1] * suf[i + 1] % mod * b[i] % mod) %= mod;	
	(f[u][0] += f[u][1]) %= mod;
}

void work()
{
    read(n); init();
    for(int i = 2, fa; i <= n; ++i) read(fa), add(fa, i);
	dfs(1);
	print(f[1][0], '\n');
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


