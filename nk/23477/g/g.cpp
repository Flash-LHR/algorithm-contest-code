#include <bits/stdc++.h>
using namespace std;

template<typename T>
void scan(T& x) {
    x = 0; int f = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

template<typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

template<typename T>
void print(T x, char ch) {
    print(x), putchar(ch);
}

typedef double db;
typedef long long ll;
typedef unsigned long long ull;

const db eps = 1e-6;
const int M = (int)1e6;
const int N = (int)20;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, m;
vector<int> g[M + 5];
int a[M + 5];
int h[M + 5][N + 1];
ll f[M + 5][2];
int dep[M + 5];

void dfs(int u, int fa) {
	for(const int& v: g[u]) {
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		h[v][0] = u;
		f[v][0] = f[u][0] + (a[u] < a[v] ? a[v] - a[u] : 0);
		f[v][1] = f[u][1] + (a[u] > a[v] ? a[u] - a[v] : 0);
		for(int i = 1; i <= N; ++i) h[v][i] = h[h[v][i - 1]][i - 1];
		dfs(v, u);
	}
}

int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = N; i >= 0; --i) {
		if(dep[h[x][i]] >= dep[y]) x = h[x][i];
		if(x == y) return x;
	}
	for(int i = N; i >= 0; --i) {
		if(h[x][i] != h[y][i]) x = h[x][i], y = h[y][i];
	}
	return h[x][0];
}

void work() {
	scan(n), scan(m);
	assert(1 <= n && n <= (int)1e6);
	for(int i = 1; i <= n; ++i) scan(a[i]);
	for(int i = 2, u, v; i <= n; ++i) {
		scan(u), scan(v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	for(int i = 1, u, v; i <= m; ++i) {
		scan(u), scan(v);
		int l = lca(u, v);
		ll ans = a[u];
		ans += f[u][1] - f[l][1] + f[v][0] - f[l][0];
		print(ans, '\n');
	}
}

int main() {
    /*ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);*/
    /*freopen("in", "r", stdin);
    freopen("out", "w", stdout);*/
    int T = 1;
    for(int ca = 1; ca <= T; ++ca) {
        work();
    }
    //cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}



