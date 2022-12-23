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
int a[M + 5];
vector<int> g[M + 5];
pair<ll, ll> f[M + 5];

void dfs(int u) {
	f[u] = make_pair(0, 0);
	ll mi = linf;
	for(const int& v: g[u]) {
		dfs(v);
		f[u].first += f[v].first + f[v].second;
		mi = min(mi, f[v].second);
	}
	if(mi == linf) f[u].first = 0, f[u].second = a[u];
	else f[u].first -= mi, f[u].second = max((ll)a[u], mi);
}

void work() {
	scan(n);
	for(int i = 0; i <= n; ++i) g[i].clear();
	for(int i = 1; i <= n; ++i) scan(a[i]);
	for(int i = 1, u; i <= n; ++i) {
		scan(u);
		g[u].push_back(i);
	}
	dfs(0);
	print(f[0].first + f[0].second, '\n');
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int T = 1; scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		printf("Case #%d: ", ca);
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

