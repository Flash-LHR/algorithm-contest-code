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
	for(int i = 1, xa, ya, xb, yb; i <= q; ++i) {
		scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
		printf("%lld\n", s[xb][yb] - s[xa - 1][yb] - s[xb][ya - 1] + s[xa - 1][ya - 1]);
	}
}

int main() {
	work();
	return 0;
}
