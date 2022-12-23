#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;

int n, m, fa[M + 5], sz[M + 5];
int a[M + 5], b[M + 5], c[M * 2 + 5];

int tofind(int x) {
	if(x == fa[x]) return x;
	return fa[x] = tofind(fa[x]);
}

void work() {
	scanf("%d", &n); m = 0;
	for(int i = 1; i <= n; ++i) {
		fa[i] = i, sz[i] = 1;
		scanf("%d %d", &a[i], &b[i]);
		c[++m] = a[i]; c[++m] = b[i];
	}
	sort(c + 1, c + m + 1);
	m = unique(c + 1, c + m + 1) - (c + 1);
	for(int i = 1; i <= n; ++i) {
		a[i] = lower_bound(c + 1, c + m + 1, a[i]) - c;
		b[i] = lower_bound(c + 1, c + m + 1, b[i]) - c;
		a[i] = tofind(a[i]), b[i] = tofind(b[i]);
		if(a[i] != b[i]) fa[a[i]] = b[i], sz[b[i]] += sz[a[i]];
	}
	int mx = 1;
	for(int i = 1; i <= n; ++i) if(i == fa[i]) {
		mx = max(mx, sz[i]);
	}
	printf("%d\n", mx);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
