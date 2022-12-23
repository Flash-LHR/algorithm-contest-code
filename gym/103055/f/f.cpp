#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)3e3;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

ll f(ll n, ll m) {
	ll mi = linf;
	for(ll l = 1, r; l <= min(n, m); l = r + 1) {
		r = m / (m / l);
		mi = min(mi, m / l * l);
	}
	return mi;
}

void work() {
	int n, m; scanf("%d %d", &n, &m);
	if(m == 1) {
		printf("%d\n", n - 1);
		return;
	} else if(m % n == 0) {
		printf("0\n");
		return;
	} else if(n >= m) {
		printf("%d\n", n - m);
		return;
	}
	ll ans = f(n, m - 1) + n - m;
	printf("%lld\n", ans);
}

int main() {
	int T = 1; scanf("%d", &T);
	while(T--) work();
	return 0;
}
