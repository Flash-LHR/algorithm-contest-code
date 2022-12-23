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
	for(int i = 1, l, r; i <= q; ++i) {
		scanf("%d %d", &l, &r);
		printf("%lld\n", s[r] - s[l - 1]);
	}
}

int main() {
	work();
	return 0;
}
