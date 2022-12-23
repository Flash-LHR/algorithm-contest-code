#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e3;

int n, m, q;
ll s[M + 5][M + 5];

void work() {
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%lld", &s[i][j]);
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	for(int i = 1, x, y; i <= q; ++i) {
		scanf("%d %d", &x, &y);
		printf("%lld\n", s[x][y]);
	}
}

int main() {
	work();
	return 0;
}
