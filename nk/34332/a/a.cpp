#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void work() {
	int a, b, n, m, h; scanf("%d%d%d%d%d", &a, &b, &n, &m, &h);
	int cnt = min((ll)(h - a) * (n / b), (ll)m - 1);
	m -= cnt;
	int l = 1, r = m, mid;
	auto check = [&](int mid) {
		ll t = (ll)(n % b + mid) / b * (h - b);
		return m - mid <= t;
	};
	while(l < r) {
		mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", n + r);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
