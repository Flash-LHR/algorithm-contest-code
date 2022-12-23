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
typedef double db;
typedef long long ll;
typedef unsigned long long ull;

const db eps = 1e-6;
const int M = (int)3e3;
const int N = (int)M * M;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const db dinf = (db)1e18;

int n, m[5];
map<pair<int, int>, int> cat;
int x[N + 5], y[N + 5], c[N + 5];
bool vis[N + 5];
db dis[N + 5];

void cal(int m, int _cat) {
	for(int i = 1, x, y; i <= m; ++i) {
		scanf("%d %d", &x, &y);
		cat[make_pair(x, y)] = _cat;
	}
}

db calDis(int u, int v) {
	if(c[v]) return 0.0;
	db dx = x[u] - x[v], dy = y[u] - y[v];
	return sqrt(dx * dx + dy * dy);
}

db prim(int s = 1) {
	for(int i = 1; i <= n; ++i) vis[i] = 0, dis[i] = dinf;
	dis[s] = 0.0;
	db ans = 0;
	for(int i = 1; i <= n; ++i) {
		int p = -1;
		for(int j = 1; j <= n; ++j) if(!vis[j] && (p == -1 || dis[j] < dis[p])) p = j;
		vis[p] = 1; ans += dis[p];
		for(int j = 1; j <= n; ++j) if(!vis[j]) {
			dis[j] = min(dis[j], calDis(p, j));
		}
	}
	return ans;
}

void work() {
	for(int i = 0; i < 5; ++i) scanf("%d", &m[i]);
	for(int i = 0; i < 5; ++i) {
		cal(m[i], i == 4);
	}
	cat[make_pair(0, 0)] = 1;
	for(const auto& p: cat) {
		++n;
		x[n] = p.first.first, y[n] = p.first.second, c[n] = p.second;
	}
	printf("%.12f\n", prim());
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

