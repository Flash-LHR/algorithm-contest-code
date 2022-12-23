#include <bits/stdc++.h>
using namespace std;

typedef double db;
typedef long long ll;

const int M = (int)1e5;

void work() {
	ll a, b, c, s;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &s);
	if(a * b == c) {
		printf("%lld\n", a * (s - 1) + c);
	} else if(a * b > c) {
		if(a <= c) printf("%lld\n", a * (s - 1) + c);
		else printf("%lld\n", a * s);
	} else if(a * b < c) {
		if(s % b != 0) {
			ll ans = s / b * c;
			s %= b;
			ans += (s - 1) * a + c;
			printf("%lld\n", ans);
		} else {
			printf("%lld\n", s / b * c + (b - 1) * a);
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
