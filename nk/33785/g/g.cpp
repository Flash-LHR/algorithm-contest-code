#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void scan(T& x) {
	x = 0; int f = 1; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
	x *= f;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

template <typename T>
void print(T x, char ch) {
	print(x), putchar(ch);
}

typedef double db;
typedef long long ll;
typedef unsigned long long ull;

const db eps = 1e-6;
const int M = (int)1e5;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n;
vector<int> g[M + 5];
int w[M + 5], c[M + 5];
ll ans[M + 5], cur;
multiset<int> st[M + 5];

void dfs(int u, int fa) {
	int nmsl = 0;
	if(st[c[u]].empty()) cur += w[u], nmsl = w[u];
	else if(-*st[c[u]].begin() < w[u]) cur -= -*st[c[u]].begin(), cur += w[u], nmsl = *st[c[u]].begin() + w[u];
	st[c[u]].insert(-w[u]);
	ans[u] = cur;
	for(const int &v: g[u]) if(v != fa) {
		dfs(v, u);
	}
	st[c[u]].erase(st[c[u]].find(-w[u]));
	cur -= nmsl;
}

void work() {
	scan(n);
	for(int i = 1; i <= n; ++i) scan(w[i]);
	for(int i = 1; i <= n; ++i) scan(c[i]);
	for(int i = 2, u, v; i <= n; ++i) {
		scan(u), scan(v);
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; ++i) print(ans[i], '\n');
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int T = 1; //scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

