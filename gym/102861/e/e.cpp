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
const int N = (int)16;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n, m, cnt;
int head[M + 5];
struct enode
{
	int v, nx;
} Edge[M * 2 + 5];

int a[M + 5];
int p[M + 5][N + 1];

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

void dfs1(int u)
{
	for(int i = head[u]; ~i; i = Edge[i].nx)
	{
		int v = Edge[i].v;
		p[v][0] = u; for(int j = 1; j <= N; ++j) p[v][j] = p[p[v][j - 1]][j - 1];
		dfs1(v);
	}
}

vector<int> st[M + 5];

int up(int o, int r)
{
	for(int i = N; ~i; --i) if(p[o][i] && a[p[o][i]] <= r) o = p[o][i];
	return o;
}

struct TA
{
    int n; int tree[M + 5];
    void init(int _n) {n = _n; for(int i = 0; i <= n; ++i) tree[i] = 0;}
    inline int lowbit(int n) {return n&-n;}
    void add(int a, int b) {for(int i = a; i <= n; i += lowbit(i)) tree[i] += b;}
    int ask(int r) {int s = 0; for(int i = r; i; i -= lowbit(i)) s += tree[i]; return s;}
    int ask(int l, int r) {return ask(r) - ask(l - 1);}
} tr;

int ans[M + 5];

void dfs2(int u)
{
	for(const auto& x: st[u]) tr.add(x, 1);
	ans[u] = tr.ask(a[u]);
	for(int i = head[u]; ~i; i = Edge[i].nx)
	{
		int v = Edge[i].v;
		dfs2(v);
	}
	for(const auto& x: st[u]) tr.add(x, -1);
}

void work()
{
	read(n), read(m); init();
	for(int i = 1, fa; i <= n; ++i)
	{
		read(a[i]), read(fa);
		if(i > 1) add(fa, i);
	}
	dfs1(1);
	for(int i = 1, o, l, r; i <= m; ++i)
	{
		read(o), read(l), read(r);
		st[up(o, r)].push_back(l);
	}
	tr.init(M);
	dfs2(1);
	for(int i = 1; i <= n; ++i) print(ans[i], i == n ? '\n' : ' ');
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


