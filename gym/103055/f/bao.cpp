#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)3e3;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

void work() {
	int n, m; scanf("%d %d", &n, &m);
	ll ans = linf;
	for(int i = 1; i <= n; ++i) {
		ans = min(ans, (m - 1ll) / i * i + n - m);
	}
	printf("%lld\n", ans);
}

int main() {
	int T = 1; scanf("%d", &T);
	while(T--) work();
	return 0;
}
