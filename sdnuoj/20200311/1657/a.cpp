#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;

int n, q;
ll s[M + 5];

void work() {
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &s[i]);
		s[i] += s[i - 1];
	}
	for(int i = 1, p; i <= q; ++i) {
		scanf("%d", &p);
		printf("%lld\n", s[p]);
	}
}

int main() {
	work();
	return 0;
}
