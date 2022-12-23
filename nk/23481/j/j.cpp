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
const int M = (int)1e7;
const int N = (int)1e5;
const ll mod = (ll)998244353;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, k;
int c[3];
int pw[M + 5];
int fac[M + 5];
int inv[M + 5];
int invfac[M + 5];

void init() {
	pw[0] = 1, pw[1] = 2;
	fac[0] = fac[1] = inv[1] = invfac[0] = invfac[1] = 1;
	for(int i = 2; i <= M; ++i) {
		pw[i] = pw[i - 1] * 2 % mod;
		fac[i] = (ll)fac[i - 1] * i % mod;
		inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
		invfac[i] = (ll)invfac[i - 1] * inv[i] % mod;
		assert((ll)fac[i] * invfac[i] % mod == 1);
	}
}

int C(int n, int m) {
	if(n < 0 || m < 0 || n < m) return 0;
	return (ll)fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

void work() {
	scan(n), scan(k);
	for(int i = 1, a; i <= n; ++i) scan(a), ++c[a];
	int ans = 0;
	for(int i = 0; i <= min(c[1], k); ++i) {
		(ans += (ll)C(c[1], i) * C(c[2], k - i) % mod * pw[k - i] % mod) %= mod;
	}
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

