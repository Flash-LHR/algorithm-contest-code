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

void work() {
	ll b, q, y; scan(b), scan(q), scan(y);
	ll c, r, z; scan(c), scan(r), scan(z);
	if((c + (z - 1) * r - b) % q || (c + (z - 1) * r - b) / q + 1 > y ||
			(c - b) % q || (c - b) / q + 1 < 1) {
		printf("0\n");
		return;
	}
	auto cal = [&](ll d) {
		ll t = c + (z - 1) * r + r;
		ll k = (t - b) / q + 1;
		if(k > y) return -1ll;
		//printf("t=%lld k=%lld\n", t, k);
		t = c - r;
		k = (t - b) / q + 1;
		//printf("t=%lld k=%lld\n", t, k);
		if(k < 1) return -1ll;
		return ((r - d) / d + 1) * ((r - d) / d + 1) % mod;
	};
	ll ans = 0;
	for(ll i = 1; i * i <= r; ++i) if(r % i == 0) {
		if(ans == -1) continue;
		if(lcm(q, i) == r) {
			ll cur = cal(i);
			//printf("%lld: %lld\n", i, cur);
			if(cur == -1) ans = -1;
			else (ans += cur) %= mod;
		}
		if(ans == -1) continue;
		if(i * i != r && lcm(q, r / i) == r) {
			ll cur = cal(r / i);
			//printf("%lld: %lld\n", r / i, cur);
			if(cur == -1) ans = -1;
			else (ans += cur) %= mod;
		}
	}
	printf("%lld\n", ans);
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

