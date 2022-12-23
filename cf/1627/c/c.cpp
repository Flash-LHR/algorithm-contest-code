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

int prime[M + 5], cnt;
bool is_prime[M + 5];

void init() {
	memset(is_prime, 1, sizeof is_prime);
	cnt = is_prime[0] = is_prime[1] = 0;
	for(int i = 2; i <= M; ++i) {
		if(is_prime[i]) prime[++cnt] = i;
		for(int j = 1; j <= cnt && i * prime[j] <= M; ++j) {
			is_prime[i * prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
	for(int i = 2; i <= 100; ++i) {
		for(int j = i; j <= 100; ++j) {
			if(is_prime[prime[i] + prime[j]]) {
				printf("%d+%d=%d\n", prime[i], prime[j], prime[i]+prime[j]);
			}
		}
	}
}

int n;
int de[M + 5];
vector<pair<int, int>> g[M + 5];
int ans[M + 5];
void dfs(int u, int fa, int nmsl) {
	for(int i = 0; i < (int)g[u].size(); ++i) {
		if(g[u][i].second == fa) continue;
		ans[g[u][i].first] = nmsl;
		dfs(g[u][i].second, u, nmsl^1);
	}
}

void work() {
	scan(n);
	for(int i = 1; i <= n; ++i) g[i].clear(), de[i] = 0;
	for(int i = 1, u, v; i < n; ++i) {
		scan(u), scan(v);
		++de[u], ++de[v];
		g[u].push_back(make_pair(i, v)), g[v].push_back(make_pair(i, u));
	}
	if(*max_element(de + 1, de + n + 1) >= 3) return print(-1, '\n'), void();
	for(int i = 1; i <= n; ++i) if(de[i] == 1){
		dfs(i, 0, 2);
		break;
	}
	for(int i = 1; i < n; ++i) print(ans[i], i == n - 1 ? '\n' : ' ');
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	//init();
	int T = 1; scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

