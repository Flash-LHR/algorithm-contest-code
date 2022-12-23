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
const int M = (int)3e3;
const int N = (int)1e5;
const ll mod = (ll)998244353;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, t;
int a[M + 5];
int f[M + 5][M + 5];
int sum[M + 5][M + 5];
int fac[M * 2 + 5];
int inv[M * 2 + 5];
int invfac[M * 2 + 5];

void init() {
	fac[0] = fac[1] = inv[1] = invfac[0] = invfac[1] = 1;
	for(int i = 2; i <= 2 * M; ++i) {
		fac[i] = (ll)fac[i - 1] * i % mod;
		inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
		invfac[i] = (ll)invfac[i - 1] * inv[i] % mod;
	}
}

int C(int n, int m) {
	if(n < 0 || m < 0 || n < m) return 0;
	return (ll)fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

int quick(int a, int b, int p = mod) {
	int s = 1;
	while(b) {
		if(b & 1) s = (ll)s * a % p;
		a = (ll)a * a % p;
		b >>= 1;
	}
	return s % p;
}

int Inv(int n, int p = mod) {
	return quick(n, p - 2, p);
}

void work() {
	init();
	scan(n), scan(t);
	f[0][0] = 1;
	for(int i = 0; i <= t; ++i) sum[0][i] = 1;
	for(int i = 1, a; i <= n; ++i) {
		scan(a);
		f[i][0] = (ll)f[i - 1][0] * a % mod;
		sum[i][0] = f[i][0];
		for(int j = 1; j <= t; ++j) {
			f[i][j] = (f[i][j - 1] + (ll)f[i - 1][j] * a + sum[i - 1][j - 1]) % mod;
			sum[i][j] = (sum[i][j - 1] + f[i][j]) % mod;
		}
	}
	int ans = (ll)f[n][t] * Inv(C(n + t - 1, t)) % mod;
	print(ans, '\n');
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

