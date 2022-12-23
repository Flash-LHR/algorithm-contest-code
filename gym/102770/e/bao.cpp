#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e3;

int n, a[M + 5];
int m, b[M + 5];
ll f[M + 5][M + 5];

ll query(int l, int r, int k) {
	for(int i = l; i <= r; ++i) b[i - l + 1] = a[i];
	for(int i = 0; i <= k; ++i) f[0][i] = 0;
	for(int i = 1; i <= r - l + 1; ++i) {
		f[i][0] = i * i + f[i - 1][0];
		for(int j = 1; j <= k; ++j) f[i][j] = i * i + max(f[i - 1][j], f[i - 1][j - 1] + b[i]);
	}
	return f[r - l + 1][k];
}

void work() {
	scanf("%d", &n); for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	int q; scanf("%d", &q);
	for(int i = 1, l, r, k; i <= q; ++i) {
		scanf("%d %d %d", &l, &r, &k);
		printf("%lld\n", query(l, r, k));
	}
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
