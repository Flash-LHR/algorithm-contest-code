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
int g[M + 5];
vector<int> v;
bool vis[M + 5];

ll cal() {
	ll ans = 0;
	for(int i = 0; i <= n; ++i) vis[i] = 0;
	for(const int& u: v) {
		int cur = u;
		int t = 0;
		while(cur && !vis[cur]) {
			t = max(t, a[cur]);
			vis[cur] = 1;
			cur = g[cur];
		}
		ans += t;
	}
	return ans;
}

void work() {
	scan(n);
	v.clear();
	for(int i = 1; i <= n; ++i) scan(a[i]), vis[i] = 0;
	for(int i = 1, u; i <= n; ++i) {
		scan(u);
		g[i] = u;
		vis[u] = 1;
	}
	for(int i = 1; i <= n; ++i) if(!vis[i]) v.push_back(i);
	ll ans = 0;
	do {
		ans = max(ans, cal());
	} while(next_permutation(v.begin(), v.end()));
	print(ans, '\n');
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

