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
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int prime[M + 5], cnt;
bool is_prime[M + 5];
int sum[M + 5];

void init() {
	memset(is_prime, 1, sizeof is_prime);
	cnt = is_prime[0] = is_prime[1] = 0;
	for(int i = 2; i <= M; ++i) {
		sum[i] = sum[i - 1];
		if(is_prime[i]) prime[++cnt] = i, ++sum[i];
		for(int j = 1; j <= cnt && i * prime[j] <= M; ++j) {
			is_prime[i * prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
}

ll quick(ll a, ll b) {
	ll s = 1;
	while(b) {
		if(b & 1) s *= a;
		a *= a;
		b >>= 1;
	}
	return s;
}

ll cal(ll n) {
	ll ans = n;
	int up = floor(pow(r, 1.0 * k));
	for(int i = 1; i <= up; ++i) if(is_prime[i]) {
		ll cur = quick(i, k);
	}
}

#if 1
void work() {
	ll l, r, k; scan(l), scan(r), scan(k);
	if(k >= 47) return print(r - l + 1, '\n'), void();
	int kl = ceil(pow(l, 1.0 / k)), kr = floor(pow(r, 1.0 / k));
	print(cal(r, k) - cal(l - 1, k), '\n');
}
#else

void work() {
}

#endif
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

