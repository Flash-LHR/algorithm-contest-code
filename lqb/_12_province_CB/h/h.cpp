#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)10;
const ll linf = 0x3f3f3f3f3f3f3f3f;

ll cal(int n, int m) {
	return (ll)n * (n + 1) / 2 + m + 1;
}

ll gao(ll n, int m) {
	if(m == 0) {
		if(n == 1) return cal(0, 0);
		else return linf;
	} else if(m == 1) {
		return cal(n, 1);
	}
	ll cur = 1;
	for(int i = m; ; ++i) {
		cur = cur * (i + 1) / (i + 1 - m);
		if(cur > n) return linf;
		if(cur == n) return cal(i + 1, m);
	}
	assert(0);
}

void work() {
	ll n; scanf("%lld", &n);
	ll mi = linf;
	for(int i = 0; i <= 16; ++i) mi = min(mi, gao(n, i));
	printf("%lld\n", mi);
}

int main() {
	work();
	return 0;
}
