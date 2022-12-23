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
const ll mod = (ll)998244353;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n;
int a[M + 5];
int ans, cnt;

void dfs(int u, int pre, int val) {
	if(u == n + 1) {
		if(~pre && val == ans) ++cnt;
		return;
	}
	dfs(u + 1, pre, val);
	if(pre == -1) dfs(u + 1, a[u], val);
	else dfs(u + 1, a[u], val + (int)abs(a[u] - pre));
}

void work() {
	scan(n);
	ans = 0, cnt = 0;
	for(int i = 1; i <= n; ++i) scan(a[i]);
	for(int i = 2; i <= n; ++i) ans += (int)abs(a[i] - a[i - 1]);
	dfs(1, -1, 0);
	printf("%d\n", cnt);
}
int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int T = 1; scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}


