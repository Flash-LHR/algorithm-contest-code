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

int n, s;
int a[M + 5];
set<int> st;

void dfs(int u) {
	if(u == n) {
		if(accumulate(a, a + n, 0) != s) return;
		int g = 0;
		for(int i = 0; i < n; ++i) g = __gcd(g, a[i]);
		st.insert(g);
		return;
	}
	for(int i = 0; i <= s; ++i) {
		a[u] = i;
		dfs(u + 1);
	}
}

int cal() {
	st.clear();
	dfs(0);
	return st.size();
}

int div(int n) {
	if(n == 1) return 1;
	int c = 0;
	for(int i = 1; (ll)i * i <= n; ++i) {
		if(n % i == 0) {
			++c;
			if(i * i != n) ++c;
		}
	}
	return c;
}

void work() {
	/*for(n = 2; n <= 10; ++n) {
		for(s = n; s <= 10; ++s) {
			printf("n=%d s=%d ans=%d\n", n, s, cal());
			assert(cal() == div(s));
		}
		printf("\n");
	}
	return;*/
	int n, s = 0; scan(n);
	for(int i = 0, a; i < n; ++i) scan(a), s += a;
	print(div(s), '\n');
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

