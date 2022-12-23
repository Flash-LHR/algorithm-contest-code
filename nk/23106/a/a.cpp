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

/*int getSum(int n) {
	int s = 0;
	while(n) {
		s += n % 10;
		n /= 10;
	}
	return s;
}

int cal(int n) {
	if(n < 10) return n;
	return cal(getSum(n));
}*/

int n;
int cnt[M + 5];
int cat[M + 5];
int ans[M + 5];

void gao() {
	for(int i = 0; i < 9; ++i) if(cat[i] > cnt[i]) return;
	int s = 0; for(int i = 0; i < 9; ++i) s += cat[i] * i;
	s %= 9;
	if(s == 2) {
		printf("cat:");
		for(int i = 0; i<9; ++i) printf(" %d", cat[i]);
		printf("\n");
	}
	int cur = quick(2, cnt[0]);
	for(int i = 1; i < 9; ++i) (cur *= (cnt[i] - cat[i]) / 9 + 1) %= mod;
	(ans[s] += cur) %= mod;
}

void dfs(int u) {
	if(u == 9) {
		gao();
		return;
	}
	for(int i = 0; i < 9; ++i) {
		cat[u] = i;
		dfs(u + 1);
	}
}

void work() {
	/*for(int i = 1; i <= 100; ++i) {
		printf("%d:%d\n", i, cal(i));
		assert(cal(i) == (i - 1) % 9 + 1);
	}*/
	scan(n);
	for(int i = 1, a; i <= n; ++i) {
		scan(a);
		++cnt[a % 9];
	}
	dfs(1);
	ans[9] = ans[0];
	for(int i = 1; i <= 9; ++i) print(ans[i], i == 9 ? '\n' : ' ');
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

