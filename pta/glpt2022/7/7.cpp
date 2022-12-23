#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void work() {
	int n, m, q; scanf("%d %d %d", &n, &m, &q);
	vector<bool> r(n, 0), c(m, 0);
	for(int i = 1, t, x; i <= q; ++i) {
		scanf("%d %d", &t, &x);
		--x;
		if(t == 0 && !r[x]) --n, r[x] = 1;
		else if(t == 1 && !c[x]) --m, c[x] = 1;
	}
	printf("%lld\n", (ll)n * m);
}

int main() {
	work();
	return 0;
}
