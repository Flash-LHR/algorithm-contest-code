#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;

int n, m, k;
int a[M + 5];
int h[M + 5];
bool vis[M + 5];

void bao(int l, int r) {
	for(int i = l; i < r; ++i) {
		if(vis[a[i % n]]) ++h[i % n], vis[a[i % n]] = 0;
		else vis[a[i % n]] = 1;
	}
}

void work() {
	scanf("%d %d %d", &n, &k, &m);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]), --a[i], h[i] = 0;
	for(int i = 0; i < k; ++i) vis[i] = 0;
	if(2 * n >= m) bao(0, m);
	else {
		bao(0, 2 * n);
		for(int i = 0; i < n; ++i) h[i] *= m / 2 / n;
		bao(m / 2 / n * 2 * n, m);
	}
	for(int i = 0; i < n; ++i) printf("%d%c", h[i], " \n"[i == n - 1]);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
