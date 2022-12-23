#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename T>
inline void scan(T &n) {
	n = 0; int f = 1; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) {n = n * 10 + ch - '0'; ch = getchar();}
	if(f == -1) n = -n;
}

const int M = (int)5e5;
const int mod = (int)998244353;

int n, x, a[M + 5];
map<int, int> cnt;

ll quick(ll a, ll b, ll p = mod) {
	ll s = 1;
	while(b) {
		if(b & 1) s = s * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return s % p;
}

ll inv(ll n, ll p = mod) {
	return quick(n, p - 2, p);
}

void work() {
	scan(n), scan(x);
	for(int i = 1; i <= n; ++i) scan(a[i]);
	if(x == 0) {
		ll ans = (ll)n * (n + 1) / 2;
		for(int l = 1, r = 0; l <= n; l = r + 1) {
			if(a[l]) while(r + 1 <= n && a[r + 1]) ++r;
			else while(r + 1 <= n && !a[r + 1]) ++r;
			if(a[l]) ans -= (ll)(r - l + 1) * (r - l + 2) / 2;
		}
		printf("%lld\n", ans);
		return;
	}
	x = inv(x);
	cnt[1] = 1;
	ll ans = 0;
	for(int i = 1, s = 1; i <= n; ++i) {
		if(a[i] == 0) {
			cnt.clear();
			s = 1;
			cnt[1] = 1;
			continue;
		} else {
		s = (ll)s * a[i] % mod;
		ans += cnt[(ll)s * x % mod];
		++cnt[s];
		}
	}
	printf("%lld\n", ans);
}

int main() {
	work();
	return 0;
}
