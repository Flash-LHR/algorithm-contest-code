#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void work() {
	ll m, n; scanf("%lld %lld", &m, &n);
	if(m == 1) {
		if(n == 1) printf("2\n");
		else printf("1\n");
	}
	else if(n == 0) printf("%lld\n", 1ll<<m);
	else printf("%lld\n", (1ll<<m) - 1);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
