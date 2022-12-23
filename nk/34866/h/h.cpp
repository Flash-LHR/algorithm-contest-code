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
const int M = (int)2e6 + 5;
const int N = (int)1e5;
const ll mod = (ll)998244353;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, m;
vector<int> g[M + 5];
int in[M + 5];
int q[M + 5];
int f[M + 5];
int inv[M + 5];

void init() {
	inv[1] = 1;
	for(int i = 2; i <= M; ++i) {
		inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
	}
}

bool topo() {
	int l = 1, r = 0;
	for(int i = 1; i <= n; ++i) if(!in[i]) {
		q[++r] = i;
	}
	int cnt = 0;
	while(l <= r) {
		int u = q[l++];
		++cnt;
		for(const int &v: g[u]) {
			f[v] += f[u] + 1;
			if(--in[v] == 0) {
				q[++r] = v;
			}
		}
	}
	return cnt == n;
}

void work() {
	scan(n), scan(m);
	for(int i = 1, u, v; i <= m; ++i) {
		scan(u), scan(v);
		g[u].push_back(v), ++in[v];
	}
	if(!topo()) return printf("0\n"), void();
	int ans = 1; for(int i = 1; i <= n; ++i) ans = (ll)ans * i % mod;
	for(int i = 1; i <= n; ++i) ans = (ll)ans * inv[f[i] + 1] % mod;
	print(ans, '\n');
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	init();
	int T = 1; //scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

