#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = (int)998244353;

ll quick(ll a, ll b, ll p = mod)
{
	ll s = 1;
	while (b) {
		if (b & 1) s = s * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return s % p;
}

void work()
{
	ll p, m; scanf("%lld %lld", &p, &m);
	p %= mod;
	ll s = p * (p - 1) / 2 % mod;
	ll ans = quick(s, m);
	printf("%lld\n", ans);
}

int main()
{
	work();
	return 0;
}
